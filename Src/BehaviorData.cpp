/*
 @file BehaviorData.cpp
*/

#include "BehaviorData.h"
#include "NodeBase.h"
#include "Enemy.h"

// ������
// test
void BehaviorData::Init()
{
	m_RunSequenceStepMap.clear();
	m_RunSelectorStepMap.clear();
	while (m_SequenceStack.size() > 0)
	{
		m_SequenceStack.pop();
	}
	while (m_SelectorStack.size() > 0)
	{
		m_SelectorStack.pop();
	}
}

// �V�[�P���X�m�[�h�̃v�b�V��
void BehaviorData::PushSequenceNode(NodeBase* node)
{
	m_SequenceStack.push(node);
}

// �V�[�P���X�m�[�h�̃|�b�v
NodeBase* BehaviorData::PopSequenceNode()
{
	// ��Ȃ�NULL
	if (m_SequenceStack.empty() != 0)
	{
		return NULL;
	}

	NodeBase* node = m_SequenceStack.top();

	if (node)
	{
		// ���o�����f�[�^���폜
		m_SequenceStack.pop();
	}

	return node;
}

// �Z���N�^�[�m�[�h�̃v�b�V��
void BehaviorData::PushSelectorNode(NodeBase* node)
{
	m_SelectorStack.push(node);
}

// �Z���N�^�[�m�[�h�̃|�b�v
NodeBase* BehaviorData::PopSelectorNode()
{
	// ��Ȃ�NULL
	if (m_SelectorStack.empty() != 0)
	{
		return NULL;
	}

	NodeBase* node = m_SelectorStack.top();

	if (node)
	{
		// ���o�����f�[�^���폜
		m_SelectorStack.pop();
	}

	return node;
}

// �m�[�h�g�p����
bool BehaviorData::IsNodeUsed(std::string name)
{
	// �g�p���ĂȂ�������false
	if (m_UseNodeMap.count(name) == 0)
	{
		return false;
	}
	return m_UseNodeMap[name];
}

// �g�p�ς݃m�[�h�ɓo�^
void BehaviorData::EntryUsedNode(std::string name)
{
	m_UseNodeMap[name] = true;
}

// �g�p�ς݃m�[�h�̃��Z�b�g
void BehaviorData::ResetNodeUsed(std::vector<NodeBase*> *reset_hierachy)
{
	for (auto itr = reset_hierachy->begin(); itr != reset_hierachy->end(); itr++)
	{
		m_UseNodeMap[(*itr)->GetName()] = false;
	}
}