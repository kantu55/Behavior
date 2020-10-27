#include <stdio.h>
#include "Enemy.h"
#include "BehaviorData.h"
#include "NodeBase.h"

/*
 �R���X�g���N�^
*/
Enemy::Enemy(BehaviorTree* ai_tree, float max_hp, float max_mp, float attack, float deffence):
	m_BehaviorTree(ai_tree),
	m_BehaviorData(NULL),
	m_ActiveNode(NULL),
	Character(max_hp, max_mp, attack, deffence)
{
	m_BehaviorData = new BehaviorData();

	m_SkillList.push_back(1);
	m_MagicList.push_back(1);
}

/*
 �r�w�C�r�A���s
*/
void Enemy::Run()
{
	if (!m_ActiveNode)
	{
		m_ActiveNode = m_BehaviorTree->Inference(this, m_BehaviorData);
	}
	if (m_ActiveNode)
	{
		m_ActiveNode = m_BehaviorTree->Run(this, m_ActiveNode, m_BehaviorData);
	}
}

/*
 �_���[�W����
*/
void Enemy::RectiveDamage(float damage)
{
	m_Hp -= damage;
}

void Enemy::PhysicsAttack()
{
	printf("�����U��\n");
}

void Enemy::Deffence()
{
	printf("���\n");
}

void Enemy::UseSkill()
{
	printf("�X�L���g�p\n");
}

void Enemy::UseMagic()
{
	printf("���@�g�p\n");
}