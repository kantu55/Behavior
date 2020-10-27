/*
 @file Character.cpp
*/

#include "Character.h"

/*
 ���݂̗̑͂��w�肵���l��荂����

 @param check_percent ��r����l
*/
bool Character::IsHpPercentOver(float check_percent)
{
	float percent = m_Hp / m_MaxHp;
	return (percent * 100.0f) >= check_percent ? true : false;
}

/*
 ���݂�MP���w�肵���l��荂����

 @param check_percent ��r����l
*/
bool Character::IsMpPercentOver(float check_percent)
{
	float percent = m_Mp / m_MaxMp;

	return (percent * 100.0f) >= check_percent ? true : false;
}

/*
 ���S���Ă��邩

 @return true  ���S
 @return false �����Ă�
*/
bool Character::IsDie()
{
	return m_Hp <= 0.0f ? true : false;
}