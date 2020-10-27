#include "SkillAttackJudgment.h"
#include "Enemy.h"

bool SkillAttackJudgment::Judgment(Enemy* enemy)
{
	return enemy->HasSkill() ? true : false;
}