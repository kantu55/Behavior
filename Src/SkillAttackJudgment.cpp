/*
 @file SkillAttackJudgment.cpp
*/

#include "SkillAttackJudgment.h"
#include "Enemy.h"

/*
 �X�L���U���p�̔���

 @return true  ���s����
 @return false ���s���Ȃ�
*/
bool SkillAttackJudgment::Judgment(Enemy* enemy)
{
	// �X�L���������Ă���Ύ��s
	return enemy->HasSkill() ? true : false;
}