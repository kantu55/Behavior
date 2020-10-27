/*
@ main.cpp ÉQÅ[ÉÄÇÃéÂóvïî
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BehaviorTree.h"
#include "AttackJudgment.h"
#include "MagicAttackJudgment.h"
#include "SkillAttackJudgment.h"
#include "DeffenceJudgment.h"
#include "PhysicsActin.h"
#include "DeffenceAction.h"
#include "MagicAction.h"
#include "SkillAction.h"
#include "Enemy.h"

int main()
{
	srand((unsigned)time(NULL));

	BehaviorTree behavior;
	behavior.AddNode("", "Root", 0, BehaviorTree::PRIORITY, NULL, NULL);
	behavior.AddNode("Root", "Attack", 1, BehaviorTree::ON_OFF, AttackJudgment::GetInstance(), NULL);
	behavior.AddNode("Root", "Deffence", 2, BehaviorTree::NON, DeffenceJudgment::GetInstance(), DeffenceAction::GetInstance());
	behavior.AddNode("Attack", "PhysicsAttack", 1, BehaviorTree::NON, NULL, PhysicsAction::GetInstance());
	behavior.AddNode("Attack", "MagicAttack", 2, BehaviorTree::NON, MagicAttackJudgment::GetInstance(), MagicAction::GetInstance());
	behavior.AddNode("Attack", "SkillAttack", 3, BehaviorTree::NON, SkillAttackJudgment::GetInstance(), SkillAction::GetInstance());
	
	behavior.PrintTree();

	Enemy enemy(&behavior, 100.0f, 100.0f, 30.0f, 10.0f);

	for (int i = 0; i < 100; i++)
	{
		if (!enemy.IsDie())
		{
			enemy.Run();
			enemy.RectiveDamage(10.0f);
		}
	}

	getchar();
	return 0;
}