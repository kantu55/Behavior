/*
 @file SkillAttackJudgment.cpp
*/

#include "SkillAttackJudgment.h"
#include "Enemy.h"

/*
 スキル攻撃用の判定

 @return true  実行する
 @return false 実行しない
*/
bool SkillAttackJudgment::Judgment(Enemy* enemy)
{
	// スキルを持っていれば実行
	return enemy->HasSkill() ? true : false;
}