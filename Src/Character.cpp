/*
 @file Character.cpp
*/

#include "Character.h"

/*
 現在の体力が指定した値より高いか

 @param check_percent 比較する値
*/
bool Character::IsHpPercentOver(float check_percent)
{
	float percent = m_Hp / m_MaxHp;
	return (percent * 100.0f) >= check_percent ? true : false;
}

/*
 現在のMPが指定した値より高いか

 @param check_percent 比較する値
*/
bool Character::IsMpPercentOver(float check_percent)
{
	float percent = m_Mp / m_MaxMp;

	return (percent * 100.0f) >= check_percent ? true : false;
}

/*
 死亡しているか

 @return true  死亡
 @return false 生きてる
*/
bool Character::IsDie()
{
	return m_Hp <= 0.0f ? true : false;
}