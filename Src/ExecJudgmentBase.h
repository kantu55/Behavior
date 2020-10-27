/*
 @file ExecJudgmentBase.h
*/

#ifndef EXEC_JUDGMENT_BASE_H_
#define EXEC_JUDGMENT_BASE_H_

class Enemy;

// ������N���X
class ExecJudgmentBase
{
public:
	virtual bool Judgment(Enemy* enemy) = 0;
};

#endif // !EXEC_JUDGMENT_BASE_H_

