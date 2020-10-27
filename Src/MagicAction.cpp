/*
 @file MagicAction.cpp
*/

#include "MagicAction.h"
#include "Enemy.h"

/*
 ���s
*/
ActionBase::STATE MagicAction::Run(Enemy* enemy)
{
	enemy->UseMagic();

	return ActionBase::STATE::COMPLETE;
}
