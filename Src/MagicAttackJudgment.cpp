/*
 @file MagicAttackJudgment.cpp
*/

#include "MagicAttackJudgment.h"
#include "Enemy.h"

/*
 ���@�U���p�̔���

 @return true  ���s����
 @return false ���s���Ȃ�
*/
bool MagicAttackJudgment::Judgment(Enemy* enemy)
{
	// �g���閂�@������AHP��50�ȏ�ł���Ύ��s
	return (enemy->HasMagic() && enemy->IsMpPercentOver(50.0f));
}