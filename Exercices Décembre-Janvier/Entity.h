#pragma once
#include "Vector2.h"
#include <SFML/Graphics.hpp>
class Entity
{
private:
	Vector2 m_position;
	sf::Drawable* m_drawable;

protected:
	Entity(Vector2 a_position, sf::Drawable* a_drawable);
	sf::Drawable* GetDrawable();
public:
	Entity();
	~Entity();
	Entity(Vector2 a_position);
	virtual void SetPosition(Vector2 a_position);
	virtual Vector2 GetPosition();
	virtual sf::Drawable* Draw();
	friend std::ostream& operator<<(std::ostream& os, const Entity& a_entity);
};

