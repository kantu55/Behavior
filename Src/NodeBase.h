/*
 @file NodeBase.h
*/

#ifndef NODE_BASE_H_
#define NODE_BASE_H_

#include <list>
#include <vector>
#include <string>
#include "BehaviorTree.h"
#include "ActionBase.h"

class ExecJudgmentBase;
class BehaviorData;

// �m�[�h
class NodeBase
{
public:
	NodeBase(std::string name, NodeBase *parent, NodeBase *sibling, int priority, BehaviorTree::SELECT_RULE select_rule, ExecJudgmentBase *exec_judgment, ActionBase *action, int hierarchy_no) :
		m_Name(name),
		m_Parent(parent),
		m_Sibling(sibling),
		m_Priority(priority),
		m_SelectRule(select_rule),
		m_ExecJudgment(exec_judgment),
		m_Action(action),
		m_HiearrchyNo(hierarchy_no),
		m_Child(NULL)
	{}

	// ���O�Q�b�^�[
	std::string GetName()
	{
		return m_Name;
	}

	// �e�m�[�h�Q�b�^�[
	NodeBase *GetParent()
	{
		return m_Parent;
	}

	// �q�m�[�h�Q�b�^�[
	NodeBase* GetChild(int idx)
	{
		return m_Child.size() >= idx ? m_Child[idx] : NULL;
	}

	// �q�m�[�h�Q�b�^�[�i�����j
	NodeBase* GetLastChild()
	{
		return m_Child.size() == 0 ? NULL : m_Child[m_Child.size() - 1];
	}

	// �q�m�[�h�Q�b�^�[�i�擪�j
	NodeBase* GetTopChild()
	{
		return m_Child.size() == 0 ? NULL : m_Child[0];
	}

	// �Z��m�[�h�Q�b�^�[
	NodeBase* GetSibling()
	{
		return m_Sibling;
	}

	// �K�w�ԍ��Q�b�^�[
	int GetHirerchyNo()
	{
		return m_HiearrchyNo;
	}

	// �D�揇�ʃQ�b�^�[
	int GetPriority()
	{
		return m_Priority;
	}

	// �e�m�[�h�Z�b�^�[
	void SetParent(NodeBase* parent)
	{
		m_Parent = parent;
	}

	// �q�m�[�h�ǉ�
	void AddChild(NodeBase* child)
	{
		m_Child.push_back(child);
	}

	// �Z��m�[�h�Z�b�^�[
	void SetSibling(NodeBase* sibling)
	{
		m_Sibling = sibling;
	}

	// �s���f�[�^�������Ă��邩
	bool HasAction()
	{
		return m_Action ? true : false;
	}

	// ���s�۔��f
	bool Judgment(Enemy* enemy);

	// �D�揇�ʑI��
	NodeBase* SelectPriority(std::vector<NodeBase*> *list);
	// �����_���I��
	NodeBase* SelectRandom(std::vector<NodeBase*> *list);
	// �I���E�I�t�I��
	NodeBase* SelectOnOff(std::vector<NodeBase*> *list, BehaviorData* data);
	// �V�[�P���X�I��
	NodeBase* SelectSequence(std::vector<NodeBase*> *list, BehaviorData* data);
	// �Z���N�^�[�I��
	NodeBase* SelectSelecor(std::vector<NodeBase*> *list, BehaviorData* data);
	// �m�[�h����
	NodeBase* SearchNode(std::string search_name);
	// �m�[�h���_
	NodeBase* Inference(Enemy* enemy, BehaviorData* data);
	// �m�[�h���\��
	void PrintName(int layer);
	// ���s
	ActionBase::STATE Run(Enemy* enemy);

protected:
	std::string m_Name;						// ���O
	BehaviorTree::SELECT_RULE m_SelectRule;	// �I�����[��
	ExecJudgmentBase *m_ExecJudgment;		// ����N���X
	ActionBase *m_Action;					// ���s�N���X
	unsigned int m_Priority;				// �D�揇��
	NodeBase *m_Parent;						// �e�m�[�h
	std::vector<NodeBase*> m_Child;			// �q�m�[�h
	NodeBase *m_Sibling;					// �Z��m�[�h
	int m_HiearrchyNo;						// �K�w�ԍ�
};


#endif // !NODE_BASE_H_

