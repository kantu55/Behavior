/*
 @file Character.h
*/

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <vector>

// �L�����N�^�[�̊��N���X
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

	// HP�Q�b�^�[
	float GetHP()
	{
		return m_Hp;
	}

	// MP�Q�b�^�[
	float GetMP()
	{
		return m_Mp;
	}

	// �U���̓Q�b�^�[
	float GetAttack()
	{
		return m_Attack;
	}

	// �h��̓Q�b�^�[
	float GetDeffence()
	{
		return m_Deffence;
	}

	// �X�L�����������Ă��邩
	bool HasSkill()
	{
		return m_SkillList.size() > 0 ? true : false;
	}

	// ���@���������Ă��邩
	bool HasMagic()
	{
		return m_MagicList.size() > 0 ? true : false;
	}

	// HP�I�[�o�[����
	bool IsHpPercentOver(float check_percent);

	// MP�I�[�o�[����
	bool IsMpPercentOver(float check_percent);

	// ���S����
	bool IsDie();

protected:
	std::vector<int> m_SkillList;	// �X�L�����X�g
	std::vector<int> m_MagicList;	// ���@���X�g

	float m_Hp;			// HP
	float m_MaxHp;		// �ő�HP
	float m_Mp;			// MP
	float m_MaxMp;		// �ő�MP
	float m_Attack;		// �U����
	float m_Deffence;	// �h���
};


#endif // !CHARACTER_H_

