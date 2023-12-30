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
	StaticObject* staticObject = new StaticObject(Vector2(rand() % 40 - 20, rand() % 40 - 20));
	BreakableObject* tower = new BreakableObject(Vector2(rand() % 40 - 20, rand() % 40 - 20), 1);

	Mob* zombi = new Mob(Vector2(rand() % 40 - 20, rand() % 40 - 20), 20, Vector2(1, 1), 10);
	Player* player = new Player(Vector2(rand() % 40 - 20, rand() % 40 - 20), 10, Vector2(1, 1), 20);

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
			BreakableObject* clostestBreakable = GetClosest<BreakableObject>(tmpMob->GetPosition());
			if (clostestBreakable != nullptr)
			{
				tmpMob->MoveToPosition(clostestBreakable->GetPosition());
			}
			
		}
		else if (dynamic_cast<Player*>(m_entities[i])) {
			Player* tmpPlayer = dynamic_cast<Player*>(m_entities[i]);
			Alive* closestAlive = GetClosest<Mob>(tmpPlayer->GetPosition());
			if (closestAlive == nullptr)
			{
				closestAlive = GetClosest<BreakableObject>(tmpPlayer->GetPosition());
			}
			if (closestAlive == nullptr)
			{
				continue;
			}
			tmpPlayer->StepToEnnemy(closestAlive, dynamic_cast<Entity*>(closestAlive)->GetPosition());
			TryRemoveDeadEntity(closestAlive);
		}
	}
}

void World::TryRemoveDeadEntity(Alive* a_target) {
	if (a_target->GetCurrentLife() <= 0)
	{
		std::vector<Entity*>::iterator index;
		index = std::find(m_entities.begin(), m_entities.end(), dynamic_cast<Entity*>(a_target));
		m_entities.erase(index);
	}
}

std::vector<sf::Drawable*> World::Draw() {

	std::vector<sf::Drawable*> result = {};
	for (int i = 0; i < m_entities.size(); i++)
	{
		result.push_back(m_entities[i]->Draw());
	}
	return result;
}

template<class T>
T* World::GetClosest(Vector2 a_position) {
	T* closest{};
	float closestDistance;
	for (int i = 0; i < m_entities.size(); i++)
	{
		T* tmp = dynamic_cast<T*>(m_entities[i]);
		if (tmp && (closest == nullptr || (abs(tmp->GetPosition().GetDistance(a_position)) < closestDistance)))
		{
			closest = tmp;
			closestDistance = abs(closest->GetPosition().GetDistance(a_position));
		}
	}
	return closest;
}