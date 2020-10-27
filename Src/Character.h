/*
 @file Character.h
*/

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <vector>

// キャラクターの基底クラス
class Character
{
public:
	Character(float hp, float mp, float attack, float deffence) :
		m_Hp(hp),
		m_MaxHp(hp),
		m_Mp(mp),
		m_MaxMp(mp),
		m_Attack(attack),
		m_Deffence(deffence)
	{};
	~Character() {};

	// HPゲッター
	float GetHP()
	{
		return m_Hp;
	}

	// MPゲッター
	float GetMP()
	{
		return m_Mp;
	}

	// 攻撃力ゲッター
	float GetAttack()
	{
		return m_Attack;
	}

	// 防御力ゲッター
	float GetDeffence()
	{
		return m_Deffence;
	}

	// スキルを所持しているか
	bool HasSkill()
	{
		return m_SkillList.size() > 0 ? true : false;
	}

	// 魔法を所持しているか
	bool HasMagic()
	{
		return m_MagicList.size() > 0 ? true : false;
	}

	// HPオーバー判定
	bool IsHpPercentOver(float check_percent);

	// MPオーバー判定
	bool IsMpPercentOver(float check_percent);

	// 死亡判定
	bool IsDie();

protected:
	std::vector<int> m_SkillList;	// スキルリスト
	std::vector<int> m_MagicList;	// 魔法リスト

	float m_Hp;			// HP
	float m_MaxHp;		// 最大HP
	float m_Mp;			// MP
	float m_MaxMp;		// 最大MP
	float m_Attack;		// 攻撃力
	float m_Deffence;	// 防御力
};


#endif // !CHARACTER_H_

