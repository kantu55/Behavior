#ifndef ATTACK_JUDGMENT_H_
#define ATTACK_JUDGMENT_H_

#include "ExecJudgmentBase.h"

class Enemy;

// UŒ‚”»’è—pƒNƒ‰ƒX
class AttackJudgment : public ExecJudgmentBase
{
public:
	static AttackJudgment* GetInstance()
	{
		static AttackJudgment m_Instance;
		return &m_Instance;
	}

	// ”»’è
	virtual bool Judgment(Enemy* enemy);
};


#endif
