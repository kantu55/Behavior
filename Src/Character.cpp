#include "Character.h"

bool Character::IsHpPercentOver(float check_percent)
{
	float percent = m_Hp / m_MaxHp;

	return (percent * 100.0f) >= check_percent ? true : false;
}

bool Character::IsMpPercentOver(float check_percent)
{
	float percent = m_Mp / m_MaxMp;

	return (percent * 100.0f) >= check_percent ? true : false;
}

bool Character::IsDie()
{
	return m_Hp <= 0.0f ? true : false;
}