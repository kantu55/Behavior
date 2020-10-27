#ifndef DEFFENCE_ACTION_H_
#define DEFFENCE_ACTION_H_

#include "ActionBase.h"

class Enemy;

// éÁîıçsìÆ
class DeffenceAction : public ActionBase
{
public:
	static DeffenceAction* GetInstance()
	{
		static DeffenceAction instance;
		return &instance;
	}

	// é¿çs
	virtual STATE Run(Enemy* enemy);
};

#endif // !DEFFENCE_ACTION_H_
