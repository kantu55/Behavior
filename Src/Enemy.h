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

	// ���s
	void Run();
	// �X�L���g�p
	void UseSkill();
	// ���@�g�p
	void UseMagic();
	// �����U��
	void PhysicsAttack();
	// ���
	void Deffence();
	// �_���[�W���f�i�f�o�b�O�p�j
	void RectiveDamage(float damage);

private:
	BehaviorTree* m_BehaviorTree;	// �r�w�C�r�A�c���[
	BehaviorData* m_BehaviorData;	// �r�w�C�r�A�f�[�^
	NodeBase* m_ActiveNode;			// ���s���m�[�h
};

#endif // !ENEMY_H_

