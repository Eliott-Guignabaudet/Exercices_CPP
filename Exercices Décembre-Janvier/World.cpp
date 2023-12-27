#include "World.h"
#include "StaticObject.h"
#include "Player.h"

World::World() : m_entities({}) {
	Init();
}

World::~World() {
	m_entities.clear();
}

void World::Init() {
	StaticObject* staticObject = new StaticObject(Vector2(10, 10));
	BreakableObject* tower = new BreakableObject(Vector2(-5, -12), 1);

	Mob* zombi = new Mob(Vector2(5, 5), 20, Vector2(1, 1), 2);
	Player* player = new Player(Vector2(0, 0), 10, Vector2(1, 1), 5);

	m_entities.push_back(staticObject);
	m_entities.push_back(tower);
	m_entities.push_back(zombi);
	m_entities.push_back(player);
}

bool World::CheckSimulationIsFinished() {
	for (int i = 0; i < m_entities.size(); i++)
	{
		if (dynamic_cast<Mob*>(m_entities[i]))
		{
			return false;
		}
		if (dynamic_cast<BreakableObject*>(m_entities[i]))
		{
			return false;
		}

	}
	std::cout << "Simulation Finished" << std::endl;
}

void World::Step() {
	for (int i = 0; i < m_entities.size(); i++)
	{
		if(dynamic_cast<Mob*>(m_entities[i])) {
			Mob* tmpMob = dynamic_cast<Mob*>(m_entities[i]);
			BreakableObject* clostestBreakable = GetClosestBreakableObject(tmpMob->GetPosition());
			if (clostestBreakable != nullptr)
			{
				tmpMob->MoveToPosition(clostestBreakable->GetPosition());
			}
			
		}
		else if (dynamic_cast<Player*>(m_entities[i])) {
			Player* tmpPlayer = dynamic_cast<Player*>(m_entities[i]);
			Mob* closestMob = GetClosestMob(tmpPlayer->GetPosition());
			if (closestMob != nullptr)
			{
				tmpPlayer->StepToEnnemy(closestMob, closestMob->GetPosition());
				if (closestMob->GetCurrentLife() <= 0)
				{
					std::vector<Entity*>::iterator index; 
					index = std::find(m_entities.begin(), m_entities.end(), closestMob);
					m_entities.erase(index);
				}
				continue;
			}
			BreakableObject* closestBreakable = GetClosestBreakableObject(tmpPlayer->GetPosition());
			if (closestBreakable != nullptr)
			{
				tmpPlayer->StepToEnnemy(closestBreakable, closestBreakable->GetPosition());
				if (closestBreakable->GetCurrentLife() <= 0)
				{
					std::vector<Entity*>::iterator index;
					index = std::find(m_entities.begin(), m_entities.end(), closestBreakable);
					m_entities.erase(index);
				}
				
			}
		}
	}
}

BreakableObject* World::GetClosestBreakableObject(Vector2 a_position) {
	BreakableObject* closest{};
	float closestDistance;
	for (int i = 0; i < m_entities.size(); i++)
	{
		BreakableObject* tmp = dynamic_cast<BreakableObject*>(m_entities[i]);
		if (tmp && (closest == nullptr || (abs(tmp->GetPosition().GetDistance(a_position)) < closestDistance)))
		{
			closest = tmp;
			closestDistance = abs(closest->GetPosition().GetDistance(a_position));
			
		}
	}
	return closest;
}

Mob* World::GetClosestMob(Vector2 a_position) {
	Mob* closest{};
	float closestDistance;
	for (int i = 0; i < m_entities.size(); i++)
	{
		Mob* tmp = dynamic_cast<Mob*>(m_entities[i]);
		if (tmp && (closest == nullptr || (abs(tmp->GetPosition().GetDistance(a_position)) < closestDistance)))
		{
			closest = tmp;
			closestDistance = abs(closest->GetPosition().GetDistance(a_position));

		}
	}
	return closest;
}
