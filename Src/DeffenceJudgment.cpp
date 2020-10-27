#include "DeffenceJudgment.h"
#include "Enemy.h"

bool DeffenceJudgment::Judgment(Enemy* enemy)
{
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