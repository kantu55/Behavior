/*
 @file Enemy.h
*/

#ifndef ENEMY_H_
#define ENEMY_H_

#include <vector>
#include "Character.h"

class BehaviorTree;
class BehaviorData;
class NodeBase;

class Enemy : public Character
{
public:
	Enemy(BehaviorTree* ai_tree, float max_hp, float max_mp, float attack, float deffence);

	// 実行
	void Run();
	// スキル使用
	void UseSkill();
	// 魔法使用
	void UseMagic();
	// 物理攻撃
	void PhysicsAttack();
	// 守備
	void Deffence();
	// ダメージ反映（デバッグ用）
	void RectiveDamage(float damage);

private:
	BehaviorTree* m_BehaviorTree;	// ビヘイビアツリー
	BehaviorData* m_BehaviorData;	// ビヘイビアデータ
	NodeBase* m_ActiveNode;			// 実行中ノード
};

#endif // !ENEMY_H_

