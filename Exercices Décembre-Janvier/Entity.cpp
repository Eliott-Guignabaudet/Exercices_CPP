#include "Entity.h"


Entity::Entity() : m_position(Vector2()), m_drawable(new sf::RectangleShape()), p_texture(sf::Texture()){
}

Entity::Entity(Vector2 a_position) : m_position(a_position), m_drawable(new sf::RectangleShape()), p_texture(sf::Texture()) {
}

Entity::Entity(Vector2 a_position, sf::Drawable* a_drawable) : m_position(a_position), m_drawable(a_drawable), p_texture(sf::Texture()) {
}

Entity::~Entity() {
	delete m_drawable;
}

sf::Drawable* Entity::GetDrawable() {
	return m_drawable;
}

void Entity::SetPosition(Vector2 a_position) {
	m_position = a_position;
}

Vector2 Entity::GetPosition() {
	return m_position;
}

sf::Drawable* Entity::Draw() {
	sf::RectangleShape* rectangle = dynamic_cast<sf::RectangleShape*>(m_drawable);
	rectangle->setPosition(m_position.x, m_position.y);
	return m_drawable;
}

std::ostream& operator<<(std::ostream& os, const Entity& a_entity) {
	os << "[Entity] Position: " << a_entity.m_position;
	return os;
}