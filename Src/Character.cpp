/*
 @file Character.cpp
*/

#include "Character.h"

/*
 Œ»İ‚Ì‘Ì—Í‚ªw’è‚µ‚½’l‚æ‚è‚‚¢‚©

 @param check_percent ”äŠr‚·‚é’l
*/
bool Character::IsHpPercentOver(float check_percent)
{
	float percent = m_Hp / m_MaxHp;
	return (percent * 100.0f) >= check_percent ? true : false;
}

/*
 Œ»İ‚ÌMP‚ªw’è‚µ‚½’l‚æ‚è‚‚¢‚©

 @param check_percent ”äŠr‚·‚é’l
*/
bool Character::IsMpPercentOver(float check_percent)
{
	float percent = m_Mp / m_MaxMp;

	return (percent * 100.0f) >= check_percent ? true : false;
}

/*
 €–S‚µ‚Ä‚¢‚é‚©

 @return true  €–S
 @return false ¶‚«‚Ä‚é
*/
bool Character::IsDie()
{
	return m_Hp <= 0.0f ? true : false;
}