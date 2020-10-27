#ifndef MAGIC_ATTACK_JUDGMENT_H_
#define MAGIC_ATTACK_JUDGMENT_H_

#include "ExecJudgmentBase.h"

class Enemy;

// ���@�s������
class MagicAttackJudgment : public ExecJudgmentBase
{
public:
	static MagicAttackJudgment* GetInstance()
	{
		static MagicAttackJudgment m_Instance;
		return &m_Instance;
	}

	virtual bool Judgment(Enemy* enemy);
};

#endif // !MAGIC_ATTACK_JUDGMENT_H_

