#include "Entity.h"


Entity::Entity() : m_position(Vector2()){}

Entity::Entity(Vector2 a_position) : m_position(a_position){}

void Entity::SetPosition(Vector2 a_position) {
	m_position = a_position;
}

Vector2 Entity::GetPosition() {
	return m_position;
}

std::ostream& operator<<(std::ostream& os, const Entity& a_entity) {
	os << "[Entity] Position: " << a_entity.m_position;
	return os;
}