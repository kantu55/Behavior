#ifndef BEHABIOR_DATA_H_
#define BEHAVIOR_DATA_H_

#include <vector>
#include <stack>
#include <map>
#include "BehaviorTree.h"

class NodeBase;
class Enemy;

// Behavior保存データ
class BehaviorData
{
public:
	BehaviorData()
	{
		Init();
	}

	// 初期化
	void Init();

	// シーケンスノードのプッシュ
	void PushSequenceNode(NodeBase* node);

	// シーケンスノードのポップ
	NodeBase* PopSequenceNode();

	// ノード使用判定
	bool IsNodeUsed(std::string name);

	// 使用済みノードに登録
	void EntryUsedNode(std::string name);

	// 使用済みのノードのリセット
	void ResetNodeUsed(std::vector<NodeBase*> *reset_hierachy);

	// シーケンスステップのセッター
	void SetSequenceStep(std::string name, int step)
	{
		m_RunSequenceStepMap[name] = step;
	}

	// シーケンスステップのゲッター
	int GetSequenceStep(std::string name)
	{
		if (m_RunSequenceStepMap.count(name) == 0)
		{
			m_RunSequenceStepMap[name] = 0;
		}
		return m_RunSequenceStepMap[name];
	}

private:
	std::stack<NodeBase*> m_SequenceStack;				// シーケンスノードスタック
	std::map<std::string, int> m_RunSequenceStepMap;	// 実行シーケンスのステップマップ
	std::map<std::string, bool> m_UseNodeMap;			// ノードの使用判定マップ
};

#endif // !BEHABIOR_DATA_H_

