#ifndef PHYSICS_ACTION_H_
#define PHYSICS_ACTION_H_

#include "ActionBase.h"

class PhysicsAction : public ActionBase
{
public:
	static PhysicsAction* GetInstance()
	{
		static PhysicsAction instance;
		return &instance;
	}

	virtual STATE Run(Enemy* enemy);
};

#endif // !PHYSICS_ACTION_H_
