/*
 @file Enemy.cpp
*/

#include <stdio.h>
#include "Enemy.h"
#include "BehaviorData.h"
#include "NodeBase.h"

/*
 コンストラクタ
*/
Enemy::Enemy(BehaviorTree* ai_tree, float max_hp, float max_mp, float attack, float deffence):
	m_BehaviorTree(ai_tree),
	m_BehaviorData(NULL),
	m_ActiveNode(NULL),
	Character(max_hp, max_mp, attack, deffence)
{
	m_BehaviorData = new BehaviorData();

	m_SkillList.push_back(1); // スキルを追加
	m_MagicList.push_back(1); // 魔法を追加
}

/*
 ビヘイビア実行
*/
void Enemy::Run()
{
	// ノードが存在していなければ、ノードを選択する
	if (!m_ActiveNode)
	{
		m_ActiveNode = m_BehaviorTree->Inference(this, m_BehaviorData);
	}
	// ノードを実行する
	if (m_ActiveNode)
	{
		m_ActiveNode = m_BehaviorTree->Run(this, m_ActiveNode, m_BehaviorData);
	}
}

/*
 ダメージ処理
*/
void Enemy::RectiveDamage(float damage)
{
	m_Hp -= damage;
}

/*
 物理攻撃
*/
void Enemy::PhysicsAttack()
{
	printf("物理攻撃\n");
}

/*
 守備
*/
void Enemy::Deffence()
{
	printf("守備\n");
}

/*
 スキルを使用
*/
void Enemy::UseSkill()
{
	printf("スキル使用\n");
}

/*
 魔法を使用
*/
void Enemy::UseMagic()
{
	printf("魔法使用\n");
}