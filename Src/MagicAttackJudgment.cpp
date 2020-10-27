/*
 @file MagicAttackJudgment.cpp
*/

#include "MagicAttackJudgment.h"
#include "Enemy.h"

/*
 魔法攻撃用の判定

 @return true  実行する
 @return false 実行しない
*/
bool MagicAttackJudgment::Judgment(Enemy* enemy)
{
	// 使える魔法があり、HPが50以上であれば実行
	return (enemy->HasMagic() && enemy->IsMpPercentOver(50.0f));
}