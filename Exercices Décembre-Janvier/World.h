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
	void TryRemoveDeadEntity(Alive* a_target);
	bool CheckSimulationIsFinished();


	template<class T = Entity>
	T* GetClosest(Vector2 a_position);
};
