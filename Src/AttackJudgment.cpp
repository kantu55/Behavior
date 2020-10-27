/*
 @file AttackJudgment.cpp
*/

#include <stdlib.h>
#include "AttackJudgment.h"
#include "Enemy.h"

/*
 UŒ‚—p‚Ì”»’è

 @return true  ŽÀs‚·‚é
 @return false ŽÀs‚µ‚È‚¢
*/
bool AttackJudgment::Judgment(Enemy* enemy)
{
	int random = 0;
	if (enemy->IsHpPercentOver(50.0f))
	{
		return true;
	}
	else if (enemy->IsHpPercentOver(30.0f))
	{
		random = 80.0f;
	}
	else
	{
		random = 50.0f;
	}

	if (rand() % 100 <= random)
	{
		return true;
	}
	return false;
}