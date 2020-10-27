#include <iostream>
#include "ExecJudgmentBase.h"
#include "NodeBase.h"
#include "Enemy.h"
#include "BehaviorData.h"
#include "ActionBase.h"

/*
 ノード検索

 @param search_name … 検索したノード
*/
NodeBase* NodeBase::SearchNode(std::string search_name)
{
	// 名前が一致したら現在検索しているノードを返す
	if (m_Name == search_name)
	{
		return this;
	}
	else
	{
		// 子ノードで検索
		for (auto itr = m_Child.begin(); itr != m_Child.end(); itr++)
		{
			// 再起関数で名前が一致するまで調べる
			NodeBase* ret = (*itr)->SearchNode(search_name);
			if (ret)
			{
				return ret;
			}
		}
	}
	// 見つからなかったらNULLで返す
	return NULL;
}

/*
 ノードを推論
 @param enemy	コントロールしているキャラクター
 @param data	ビヘイビアデータ
*/
NodeBase* NodeBase::Inference(Enemy* enemy, BehaviorData* data)
{
	std::vector<NodeBase*> list;
	NodeBase* result = NULL;

	// 子ノードで実行可能なノードを探す
	for (int i = 0; i < m_Child.size(); i++)
	{
		// 判定クラスを持っているか
		if (m_Child[i]->m_ExecJudgment != NULL)
		{
			// 判定クラスで実行可能ならlistにノードを追加する
			if (m_Child[i]->m_ExecJudgment->Judgment(enemy))
			{
				list.push_back(m_Child[i]);
			}
		}
		else
		{
			// 判定クラスがなければ無条件に追加
			list.push_back(m_Child[i]);
		}
	}

	// 選択ルールでノード決め
	switch (m_SelectRule)
	{
	// 優先順位
	case BehaviorTree::PRIORITY:
		result = SelectPriority(&list);
		break;
	// シーケンス・シーケンシャルルーピング
	case BehaviorTree::SEQUENCE:
	case BehaviorTree::SEQUENTIAL_LOOPING:
		result = SelectSequence(&list, data);
		break;
	// ランダム
	case BehaviorTree::RANDOM:
		result = SelectRandom(&list);
		break;
	// オン・オフ
	case BehaviorTree::ON_OFF:
		result = SelectOnOff(&list, data);
		break;
	}

	if (result)
	{
		// 行動があれば終了
		if (result->HasAction())
		{
			return result;
		}
		else
		// 決まったノードで推論開始
		{
			result = result->Inference(enemy, data);
		}
	}

	return result;
}

// 優先順位
NodeBase* NodeBase::SelectPriority(std::vector<NodeBase*> *list)
{
	NodeBase* select_node = NULL;
	int priority = -10000;

	// 優先順位の高いノードを探す
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

// オン・オフ
NodeBase* NodeBase::SelectOnOff(std::vector<NodeBase*> *list, BehaviorData* data)
{
	std::vector<NodeBase*> off_list;

	// 使用済みノードをリストアップする
	for (auto itr = list->begin(); itr != list->end(); itr++)
	{
		if (!data->IsNodeUsed((*itr)->GetName()))
		{
			off_list.push_back(*itr);
		}
	}

	// リストアップした数を確認
	if (off_list.size() == 0)
	{
		// ノードを全てリセット
		data->ResetNodeUsed(&m_Child);
		off_list = *list;
	}

	// 使用したノードを登録
	data->EntryUsedNode(off_list[0]->GetName());

	// リストの先頭が決定ノード
	return off_list[0];
}

// ランダム
NodeBase* NodeBase::SelectRandom(std::vector<NodeBase*> *list)
{
	int select_no = rand() % list->size();
	return (*list)[select_no];
}

// シーケンス
NodeBase* NodeBase::SelectSequence(std::vector<NodeBase*> *list, BehaviorData* data)
{
	// 今のノードのシーケンスのステップを取得
	int step = data->GetSequenceStep(GetName());

	// シーケンスが終わったら終了
	if (step >= m_Child.size())
	{
		if (m_SelectRule != BehaviorTree::SELECT_RULE::SEQUENTIAL_LOOPING)
		{
			return NULL;
		}
		else
		{
			// Loopingの場合は頭から実行
			step = 0;
		}
	}

	// 順番のノードが実行できているかチェック
	for (auto itr = list->begin(); itr != list->end(); itr++)
	{
		if (m_Child[step]->GetName() == (*itr)->GetName())
		{
			// シーケンスノードを記録
			data->PushSequenceNode(this);
			// シーケンスステップを更新
			data->SetSequenceStep(GetName(), step + 1);
			return m_Child[step];
		}
	}

	return NULL;
}

// 成功判定
bool NodeBase::Judgment(Enemy* enemy)
{
	// 判定クラスを持っていなければtrue扱い
	return m_ExecJudgment ? m_ExecJudgment->Judgment(enemy) : true;
}

// ノードを実行
ActionBase::STATE NodeBase::Run(Enemy* enemy)
{
	// アクションノードがあれば実行して結果を返す、なければ失敗を返す
	if (m_Action)
	{
		return m_Action->Run(enemy);
	}
	return ActionBase::FAILED;
}

// 名前表示
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