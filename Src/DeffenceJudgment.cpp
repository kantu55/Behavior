/*
 @file DeffenceJudgment.cpp
*/

#include "DeffenceJudgment.h"
#include "Enemy.h"

/*
 守備用の判定

 @return true  実行する
 @return false 実行しない
*/
bool DeffenceJudgment::Judgment(Enemy* enemy)
{
	// HPが50を下回っているか
	if (!enemy->IsHpPercentOver(50.0f))
	{
		int random = rand() % 100;

		if (random <= 40.0f)
		{
			return true;
		}
	}
	return false;
}