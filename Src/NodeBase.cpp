#include <iostream>
#include "ExecJudgmentBase.h"
#include "NodeBase.h"
#include "Enemy.h"
#include "BehaviorData.h"
#include "ActionBase.h"

/*
 �m�[�h����

 @param search_name �c ���������m�[�h
*/
NodeBase* NodeBase::SearchNode(std::string search_name)
{
	// ���O����v�����猻�݌������Ă���m�[�h��Ԃ�
	if (m_Name == search_name)
	{
		return this;
	}
	else
	{
		// �q�m�[�h�Ō���
		for (auto itr = m_Child.begin(); itr != m_Child.end(); itr++)
		{
			// �ċN�֐��Ŗ��O����v����܂Œ��ׂ�
			NodeBase* ret = (*itr)->SearchNode(search_name);
			if (ret)
			{
				return ret;
			}
		}
	}
	// ������Ȃ�������NULL�ŕԂ�
	return NULL;
}

/*
 �m�[�h�𐄘_
 @param enemy	�R���g���[�����Ă���L�����N�^�[
 @param data	�r�w�C�r�A�f�[�^
*/
NodeBase* NodeBase::Inference(Enemy* enemy, BehaviorData* data)
{
	std::vector<NodeBase*> list;
	NodeBase* result = NULL;

	// �q�m�[�h�Ŏ��s�\�ȃm�[�h��T��
	for (int i = 0; i < m_Child.size(); i++)
	{
		// ����N���X�������Ă��邩
		if (m_Child[i]->m_ExecJudgment != NULL)
		{
			// ����N���X�Ŏ��s�\�Ȃ�list�Ƀm�[�h��ǉ�����
			if (m_Child[i]->m_ExecJudgment->Judgment(enemy))
			{
				list.push_back(m_Child[i]);
			}
		}
		else
		{
			// ����N���X���Ȃ���Ζ������ɒǉ�
			list.push_back(m_Child[i]);
		}
	}

	// �I�����[���Ńm�[�h����
	switch (m_SelectRule)
	{
	// �D�揇��
	case BehaviorTree::PRIORITY:
		result = SelectPriority(&list);
		break;
	// �V�[�P���X�E�V�[�P���V�������[�s���O
	case BehaviorTree::SEQUENCE:
	case BehaviorTree::SEQUENTIAL_LOOPING:
		result = SelectSequence(&list, data);
		break;
	// �����_��
	case BehaviorTree::RANDOM:
		result = SelectRandom(&list);
		break;
	// �I���E�I�t
	case BehaviorTree::ON_OFF:
		result = SelectOnOff(&list, data);
		break;
	}

	if (result)
	{
		// �s��������ΏI��
		if (result->HasAction())
		{
			return result;
		}
		else
		// ���܂����m�[�h�Ő��_�J�n
		{
			result = result->Inference(enemy, data);
		}
	}

	return result;
}

// �D�揇��
NodeBase* NodeBase::SelectPriority(std::vector<NodeBase*> *list)
{
	NodeBase* select_node = NULL;
	int priority = -10000;

	// �D�揇�ʂ̍����m�[�h��T��
	for (auto itr = list->begin(); itr != list->end(); itr++)
	{
		if (priority < (*itr)->GetPriority())
		{
			select_node = (*itr);
			priority = (*itr)->GetPriority();
		}
	}

	return select_node;
}

// �I���E�I�t
NodeBase* NodeBase::SelectOnOff(std::vector<NodeBase*> *list, BehaviorData* data)
{
	std::vector<NodeBase*> off_list;

	// �g�p�ς݃m�[�h�����X�g�A�b�v����
	for (auto itr = list->begin(); itr != list->end(); itr++)
	{
		if (!data->IsNodeUsed((*itr)->GetName()))
		{
			off_list.push_back(*itr);
		}
	}

	// ���X�g�A�b�v���������m�F
	if (off_list.size() == 0)
	{
		// �m�[�h��S�ă��Z�b�g
		data->ResetNodeUsed(&m_Child);
		off_list = *list;
	}

	// �g�p�����m�[�h��o�^
	data->EntryUsedNode(off_list[0]->GetName());

	// ���X�g�̐擪������m�[�h
	return off_list[0];
}

// �����_��
NodeBase* NodeBase::SelectRandom(std::vector<NodeBase*> *list)
{
	int select_no = rand() % list->size();
	return (*list)[select_no];
}

// �V�[�P���X
NodeBase* NodeBase::SelectSequence(std::vector<NodeBase*> *list, BehaviorData* data)
{
	// ���̃m�[�h�̃V�[�P���X�̃X�e�b�v���擾
	int step = data->GetSequenceStep(GetName());

	// �V�[�P���X���I�������I��
	if (step >= m_Child.size())
	{
		if (m_SelectRule != BehaviorTree::SELECT_RULE::SEQUENTIAL_LOOPING)
		{
			return NULL;
		}
		else
		{
			// Looping�̏ꍇ�͓�������s
			step = 0;
		}
	}

	// ���Ԃ̃m�[�h�����s�ł��Ă��邩�`�F�b�N
	for (auto itr = list->begin(); itr != list->end(); itr++)
	{
		if (m_Child[step]->GetName() == (*itr)->GetName())
		{
			// �V�[�P���X�m�[�h���L�^
			data->PushSequenceNode(this);
			// �V�[�P���X�X�e�b�v���X�V
			data->SetSequenceStep(GetName(), step + 1);
			return m_Child[step];
		}
	}

	return NULL;
}

// ��������
bool NodeBase::Judgment(Enemy* enemy)
{
	// ����N���X�������Ă��Ȃ����true����
	return m_ExecJudgment ? m_ExecJudgment->Judgment(enemy) : true;
}

// �m�[�h�����s
ActionBase::STATE NodeBase::Run(Enemy* enemy)
{
	// �A�N�V�����m�[�h������Ύ��s���Č��ʂ�Ԃ��A�Ȃ���Ύ��s��Ԃ�
	if (m_Action)
	{
		return m_Action->Run(enemy);
	}
	return ActionBase::FAILED;
}

// ���O�\��
void NodeBase::PrintName(int layer)
{

	for (int i = 0; i < layer; i++)
	{
		printf("\t");
	}
	std::cout << m_Name << std::endl;

	layer++;
	for (auto itr = m_Child.begin(); itr != m_Child.end(); itr++)
	{
		(*itr)->PrintName(layer);
	}
}