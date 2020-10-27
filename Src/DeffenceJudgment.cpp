/*
 @file DeffenceJudgment.cpp
*/

#include "DeffenceJudgment.h"
#include "Enemy.h"

/*
 ����p�̔���

 @return true  ���s����
 @return false ���s���Ȃ�
*/
bool DeffenceJudgment::Judgment(Enemy* enemy)
{
	// HP��50��������Ă��邩
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