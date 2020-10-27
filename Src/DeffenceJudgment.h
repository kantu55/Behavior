/*
 @file DeffenceJudgment.h
*/

#ifndef DEFFENCE_JUDGMENT_H_
#define DEFFENCE_JUDGMENT_H_

#include "ExecJudgmentBase.h"

// éÁîıé¿çsîªíË
class DeffenceJudgment : public ExecJudgmentBase
{
public:
	static DeffenceJudgment* GetInstance()
	{
		static DeffenceJudgment instance;
		return &instance;
	}

	virtual bool Judgment(Enemy* enemy);
};

#endif // !DEFFENCE_JUDGMENT_H_

