#include "MagicAttackJudgment.h"
#include "Enemy.h"

bool MagicAttackJudgment::Judgment(Enemy* enemy)
{
	return (enemy->HasMagic() && enemy->IsMpPercentOver(50.0f));
}