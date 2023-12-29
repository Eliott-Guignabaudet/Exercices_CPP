#include "StaticObject.h"

StaticObject::StaticObject() : Entity(){
	DisplayCreationMessage();
}

StaticObject::StaticObject(Vector2 a_position) : Entity(a_position, new sf::RectangleShape(sf::Vector2f(2.f, 2.f))) {
	DisplayCreationMessage();
}

void StaticObject::DisplayCreationMessage() {
	std::cout
		<< "Static Object just created at x = "
		<< GetPosition().x
		<< " and y = "
		<< GetPosition().y
		<< std::endl;
}

sf::Drawable* StaticObject::Draw() {
	sf::RectangleShape* rectangle = dynamic_cast<sf::RectangleShape*>(GetDrawable());
	rectangle->setFillColor(sf::Color(255,50,187));
	rectangle->setPosition(GetPosition().x, GetPosition().y);
	return rectangle;
}