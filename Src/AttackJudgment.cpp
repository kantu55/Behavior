/*
 @file AttackJudgment.cpp
*/

#include <stdlib.h>
#include "AttackJudgment.h"
#include "Enemy.h"

/*
 攻撃用の判定

 @return true  実行する
 @return false 実行しない
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