/*
 @file MagicAction.h
*/

#ifndef MAGIC_ACTION_H_
#define MAGIC_ACTION_H_

#include "ActionBase.h"

// ���@�s��
class MagicAction : public ActionBase
{
public:
	static MagicAction *GetInstance()
	{
		static MagicAction instance;
		return &instance;
	}

	virtual STATE Run(Enemy* enemy);
};

#endif // !MAGIC_ACTION_H_
