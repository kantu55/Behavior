/*
 @file BehaviorTree.cpp
*/
#include "BehaviorTree.h"
#include "ActionBase.h"
#include "NodeBase.h"
#include "ExecJudgmentBase.h"
#include "Enemy.h"
#include "BehaviorData.h"

/*
 �m�[�h�̒ǉ�
 @param search_name	�e�m�[�h
 @param entry_name	�ǉ��������m�[�h
 @param priority	�D�揇��
 @param select_rule	�I�����[��
 @param judgment	����
 @param action		���s
*/
void BehaviorTree::AddNode(std::string search_name, std::string entry_name, int priority, SELECT_RULE select_rule, ExecJudgmentBase *judgment, ActionBase *action)
{
	if (search_name != "")
	{
		// �m�[�h�̌���
		NodeBase* search_node = m_Root->SearchNode(search_name);

		if (search_node)
		{
			// �m�[�h�̒ǉ�
			NodeBase* sibling = search_node->GetLastChild();
			NodeBase* add_node = new NodeBase(entry_name, search_node, sibling, priority, select_rule, judgment, action, search_node->GetHirerchyNo() + 1);
			search_node->AddChild(add_node);
		}
	}
	else
	{
		// ���[�g��ǉ�
		if (!m_Root)
		{
			m_Root = new NodeBase(entry_name, NULL, NULL, priority, select_rule, judgment, action, 1);
		}
		else
		{
			printf("���[�g�͊��ɓo�^����Ă��܂�");
		}
	}
}

// ���O�\��
void BehaviorTree::PrintTree()
{
	if (m_Root)
	{
		m_Root->PrintName(0);
	}
}

/*
 ���_
 @param enemy	�c �R���g���[������Ă���L�����N�^�[
 @param data	�c �f�[�^
*/
NodeBase* BehaviorTree::Inference(Enemy* enemy, BehaviorData* data)
{
	// �f�[�^�����Z�b�g
	data->Init();
	// ���[�g���琄�_���ăm�[�h��I������
	return m_Root->Inference(enemy, data);
}

/*
 �V�[�P���X�m�[�h����̐��_�J�n
 @param sequence_node	
 @param enemy			�R���g���[������Ă���L�����N�^�[
 @param data			�f�[�^
 */
NodeBase* BehaviorTree::SequenceBack(NodeBase* sequence_node, Enemy* enemy, BehaviorData* data)
{
	return sequence_node->Inference(enemy, data);
}

/*
 �m�[�h���s
 @param enemy		�R���g���[������Ă�L�����N�^�[
 @param action_node	���ݎ��s���Ă���m�[�h
 @param data		�r�w�C�r�A���Ǘ�����f�[�^
*/
NodeBase* BehaviorTree::Run(Enemy* enemy, NodeBase* action_node, BehaviorData* data)
{
	// �m�[�h���s
	ActionBase::STATE state = action_node->Run(enemy);

	// ����I��
	if (state == ActionBase::STATE::COMPLETE)
	{
		// �V�[�P���X�̓r�����𔻒f
		NodeBase* sequence_node = data->PopSequenceNode();

		if (!sequence_node)
		{
			// �r������Ȃ��Ȃ�I��
			return NULL;
		}
		else
		{
			// �r���Ȃ炻������n�߂�
			return SequenceBack(sequence_node, enemy, data);
		}
	}
	// ���s�͏I��
	else if (state == ActionBase::STATE::FAILED)
	{
		return NULL;
	}

	// ����ێ�
	return action_node;
}