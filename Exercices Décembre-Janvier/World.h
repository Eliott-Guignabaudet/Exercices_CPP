#pragma once
#include <vector>
#include "BreakableObject.h"
#include "Mob.h"
class World
{
private:
	std::vector<Entity*> m_entities;
	void Init();
	void TryRemoveDeadEntity(Alive* a_target);
	template<class T = Entity>
	T* GetClosest(Vector2 a_position);


public:
	World();
	~World();
	void Step();
	bool CheckSimulationIsFinished();


};
