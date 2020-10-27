/*
 @file DeffenceAction.cpp
*/

#include <stdio.h>
#include "DeffenceAction.h"
#include "Enemy.h"

/*
 ŽÀs
*/
ActionBase::STATE DeffenceAction::Run(Enemy* enemy)
{
	enemy->Deffence();

	return ActionBase::STATE::COMPLETE;
}
