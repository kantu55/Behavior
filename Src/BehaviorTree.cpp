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
 ノードの追加
 @param search_name	親ノード
 @param entry_name	追加したいノード
 @param priority	優先順位
 @param select_rule	選択ルール
 @param judgment	判定
 @param action		実行
*/
void BehaviorTree::AddNode(std::string search_name, std::string entry_name, int priority, SELECT_RULE select_rule, ExecJudgmentBase *judgment, ActionBase *action)
{
	if (search_name != "")
	{
		// ノードの検索
		NodeBase* search_node = m_Root->SearchNode(search_name);

		if (search_node)
		{
			// ノードの追加
			NodeBase* sibling = search_node->GetLastChild();
			NodeBase* add_node = new NodeBase(entry_name, search_node, sibling, priority, select_rule, judgment, action, search_node->GetHirerchyNo() + 1);
			search_node->AddChild(add_node);
		}
	}
	else
	{
		// ルートを追加
		if (!m_Root)
		{
			m_Root = new NodeBase(entry_name, NULL, NULL, priority, select_rule, judgment, action, 1);
		}
		else
		{
			printf("ルートは既に登録されています");
		}
	}
}

// 名前表示
void BehaviorTree::PrintTree()
{
	if (m_Root)
	{
		m_Root->PrintName(0);
	}
}

/*
 推論
 @param enemy	… コントロールされているキャラクター
 @param data	… データ
*/
NodeBase* BehaviorTree::Inference(Enemy* enemy, BehaviorData* data)
{
	// データをリセット
	data->Init();
	// ルートから推論してノードを選択する
	return m_Root->Inference(enemy, data);
}

/*
 シーケンスノードからの推論開始
 @param sequence_node	
 @param enemy			コントロールされているキャラクター
 @param data			データ
 */
NodeBase* BehaviorTree::SequenceBack(NodeBase* sequence_node, Enemy* enemy, BehaviorData* data)
{
	return sequence_node->Inference(enemy, data);
}

/*
 ノード実行
 @param enemy		コントロールされてるキャラクター
 @param action_node	現在実行しているノード
 @param data		ビヘイビアを管理するデータ
*/
NodeBase* BehaviorTree::Run(Enemy* enemy, NodeBase* action_node, BehaviorData* data)
{
	// ノード実行
	ActionBase::STATE state = action_node->Run(enemy);

	// 正常終了
	if (state == ActionBase::STATE::COMPLETE)
	{
		// シーケンスの途中かを判断
		NodeBase* sequence_node = data->PopSequenceNode();

		if (!sequence_node)
		{
			// 途中じゃないなら終了
			return NULL;
		}
		else
		{
			// 途中ならそこから始める
			return SequenceBack(sequence_node, enemy, data);
		}
	}
	// 失敗は終了
	else if (state == ActionBase::STATE::FAILED)
	{
		return NULL;
	}

	// 現状維持
	return action_node;
}