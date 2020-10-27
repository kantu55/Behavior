/*
 @file DeffenceJudgment.cpp
*/

#include "DeffenceJudgment.h"
#include "Enemy.h"

/*
 Žç”õ—p‚Ì”»’è

 @return true  ŽÀs‚·‚é
 @return false ŽÀs‚µ‚È‚¢
*/
bool DeffenceJudgment::Judgment(Enemy* enemy)
{
	// HP‚ª50‚ð‰º‰ñ‚Á‚Ä‚¢‚é‚©
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