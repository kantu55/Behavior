#include "PhysicsActin.h"
#include "Enemy.h"

ActionBase::STATE PhysicsAction::Run(Enemy* enemy)
{
	enemy->PhysicsAttack();

	return ActionBase::STATE::COMPLETE;
}