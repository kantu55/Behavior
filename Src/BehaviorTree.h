/*
 @file BehaviorTree.h
*/

#ifndef BEHAVIOR_TREE_H_
#define BEHAVIOR_TREE_H_

#include <string>

class ActionBase;
class ExecJudgmentBase;
class NodeBase;
class BehaviorData;
class Enemy;

// ビヘイビアツリー
class BehaviorTree
{
public:
	// 選択ルール
	enum SELECT_RULE
	{
		NON,
		PRIORITY,			// 優先順位
		SEQUENCE,			// シーケンス
		SEQUENTIAL_LOOPING,	// シーケンシャルルーピング
		RANDOM,				// ランダム
		ON_OFF,				// オン・オフ
		Selector,			// セレクター
	};

public:
	BehaviorTree() :
		m_Root(NULL)
	{};

	// 実行ノードを推論する
	NodeBase *Inference(Enemy *enemy, BehaviorData *data);

	// シーケンスノードから推論開始
	NodeBase *SequenceBack(NodeBase *sequence_node, Enemy *enemy, BehaviorData *data);

	/*
	 ノードの追加
	 @param search_name	 … 親ノード
	 @param entry_name	 … 追加したいノード
	 @param priority	 … 優先順位
	 @param select_rule	 … 選択ルール
	 @param judgment	 … 判定
	 @param action		 … 実行
	*/
	void AddNode(std::string search_name, std::string entry_name, int priority, SELECT_RULE select_rule, ExecJudgmentBase *judgment, ActionBase *action);

	// ツリー構造を表示
	void PrintTree();

	// 実行
	NodeBase *Run(Enemy *enemy, NodeBase *action_node, BehaviorData *data);

private:
	// ルートノード
	NodeBase *m_Root;
};

#endif // !BEHAVIOR_TREE_H_

