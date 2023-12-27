#pragma once
#include <vector>
#include "BreakableObject.h"
#include "Mob.h"
class World
{
private:
	std::vector<Entity*> m_entities;
	void Init();
public:
	World();
	~World();
	void Step();
	bool CheckSimulationIsFinished();
	BreakableObject* GetClosestBreakableObject(Vector2 a_position);
	Mob* GetClosestMob(Vector2 a_position);
};
