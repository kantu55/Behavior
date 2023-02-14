/*
 @file BehaviorData.cpp
*/

#include "BehaviorData.h"
#include "NodeBase.h"
#include "Enemy.h"

// 初期化
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

// シーケンスノードのプッシュ
void BehaviorData::PushSequenceNode(NodeBase* node)
{
	m_SequenceStack.push(node);
}

// シーケンスノードのポップ
NodeBase* BehaviorData::PopSequenceNode()
{
	// 空ならNULL
	if (m_SequenceStack.empty() != 0)
	{
		return NULL;
	}

	NodeBase* node = m_SequenceStack.top();

	if (node)
	{
		// 取り出したデータを削除
		m_SequenceStack.pop();
	}

	return node;
}

// セレクターノードのプッシュ
void BehaviorData::PushSelectorNode(NodeBase* node)
{
	m_SelectorStack.push(node);
}

// セレクターノードのポップ
NodeBase* BehaviorData::PopSelectorNode()
{
	// 空ならNULL
	if (m_SelectorStack.empty() != 0)
	{
		return NULL;
	}

	NodeBase* node = m_SelectorStack.top();

	if (node)
	{
		// 取り出したデータを削除
		m_SelectorStack.pop();
	}

	return node;
}

// ノード使用判定
bool BehaviorData::IsNodeUsed(std::string name)
{
	// 使用してなかったらfalse
	if (m_UseNodeMap.count(name) == 0)
	{
		return false;
	}
	return m_UseNodeMap[name];
}

// 使用済みノードに登録
void BehaviorData::EntryUsedNode(std::string name)
{
	m_UseNodeMap[name] = true;
}

// 使用済みノードのリセット
void BehaviorData::ResetNodeUsed(std::vector<NodeBase*> *reset_hierachy)
{
	for (auto itr = reset_hierachy->begin(); itr != reset_hierachy->end(); itr++)
	{
		m_UseNodeMap[(*itr)->GetName()] = false;
	}
}