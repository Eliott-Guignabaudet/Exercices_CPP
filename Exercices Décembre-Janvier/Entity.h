#pragma once
#include "Vector2.h"
class Entity
{
private:
	Vector2 m_position;

public:
	Entity();
	Entity(Vector2 a_position);
	virtual void SetPosition(Vector2 a_position);
	virtual Vector2 GetPosition();

	friend std::ostream& operator<<(std::ostream& os, const Entity& a_entity);
};

