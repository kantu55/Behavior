/*
@file BehaviorData.h
*/

#ifndef BEHABIOR_DATA_H_
#define BEHAVIOR_DATA_H_

#include <vector>
#include <stack>
#include <map>
#include "BehaviorTree.h"

class NodeBase;
class Enemy;

// Behavior�ۑ��f�[�^
class BehaviorData
{
public:
	BehaviorData()
	{
		Init();
	}

	// ������
	void Init();

	// �m�[�h�g�p����
	bool IsNodeUsed(std::string name);

	// �g�p�ς݃m�[�h�ɓo�^
	void EntryUsedNode(std::string name);

	// �g�p�ς݂̃m�[�h�̃��Z�b�g
	void ResetNodeUsed(std::vector<NodeBase*> *reset_hierachy);

	// �V�[�P���X�m�[�h�̃v�b�V��
	void PushSequenceNode(NodeBase* node);
	
	// �V�[�P���X�m�[�h�̃|�b�v
	NodeBase* PopSequenceNode();

	// �V�[�P���X�X�e�b�v�̃Z�b�^�[
	void SetSequenceStep(std::string name, int step)
	{
		m_RunSequenceStepMap[name] = step;
	}

	// �V�[�P���X�X�e�b�v�̃Q�b�^�[
	int GetSequenceStep(std::string name)
	{
		if (m_RunSequenceStepMap.count(name) == 0)
		{
			m_RunSequenceStepMap[name] = 0;
		}
		return m_RunSequenceStepMap[name];
	}

	// �Z���N�^�[�m�[�h�̃v�b�V��
	void PushSelectorNode(NodeBase* node);

	// �Z���N�^�[�m�[�h�̃|�b�v
	NodeBase* PopSelectorNode();

	// �Z���N�^�[�X�e�b�v�̃Z�b�^�[
	void SetSelectorStep(std::string name, int step)
	{
		m_RunSelectorStepMap[name] = step;
	}

	// �Z���N�^�[�X�e�b�v�̃Q�b�^�[
	int GetSelectorStep(std::string name)
	{
		if (m_RunSelectorStepMap.count(name) == 0)
		{
			m_RunSelectorStepMap[name] = 0;
		}
		return m_RunSelectorStepMap[name];
	}

private:
	std::stack<NodeBase*> m_SequenceStack;				// �V�[�P���X�m�[�h�X�^�b�N
	std::map<std::string, int> m_RunSequenceStepMap;	// ���s�V�[�P���X�̃X�e�b�v�}�b�v
	std::stack<NodeBase*> m_SelectorStack;				// �Z���N�^�[�m�[�h�̃X�^�b�N
	std::map<std::string, int> m_RunSelectorStepMap;	// ���s�Z���N�^�[�̃X�e�b�v�}�b�v
	std::map<std::string, bool> m_UseNodeMap;			// �m�[�h�̎g�p����}�b�v
};

#endif // !BEHABIOR_DATA_H_

