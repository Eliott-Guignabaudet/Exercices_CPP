#include "BreakableObject.h"

BreakableObject::BreakableObject() : Entity(), Alive(){
	DisplayCreationMessage();
}

BreakableObject::BreakableObject(Vector2 a_position, float a_maxLife) : Entity(a_position, new sf::RectangleShape(sf::Vector2f(2.f,2.f))), Alive(a_maxLife){
	DisplayCreationMessage();
}

void BreakableObject::DisplayCreationMessage(){
	std::cout
		<< "Breakable Object just created at x = "
		<< GetPosition().x
		<< " and y = "
		<< GetPosition().y
		<< " with "
		<< GetCurrentLife()
		<< " life"
		<< std::endl;
}

void BreakableObject::DisplayBrokeMessage() {
	std::cout << "Breakable Object just broke" << std::endl;
}


void BreakableObject::TakeDamage(float a_damage) {
	Alive::TakeDamage(a_damage);
	if (GetCurrentLife() <= 0)
	{
		DisplayBrokeMessage();
	}
}

sf::Drawable* BreakableObject::Draw() {
	sf::RectangleShape* rectangle = dynamic_cast<sf::RectangleShape*>(GetDrawable());
	rectangle->setPosition(GetPosition().x, GetPosition().y);
	rectangle->setFillColor(sf::Color(255,128,0));
	return rectangle;
}