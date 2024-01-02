#include "BreakableObject.h"

BreakableObject::BreakableObject() : Entity(), Alive(){
	Load();
	DisplayCreationMessage();
}

BreakableObject::BreakableObject(Vector2 a_position, float a_maxLife) : Entity(a_position, new sf::Sprite()), Alive(a_maxLife){
	Load();
	DisplayCreationMessage();
}

void BreakableObject::Load() {
	if (!p_texture.loadFromFile("Assets/Sprites/spaceMeteors_001.png"))
	{
		std::cout << "Texture don't load" << std::endl;
		return;
	}
	sf::Sprite* sprite = dynamic_cast<sf::Sprite*>(GetDrawable());
	sprite->setTexture(p_texture);
	sprite->setScale(0.0125f, 0.0125f);
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
	//sf::RectangleShape* rectangle = dynamic_cast<sf::RectangleShape*>(GetDrawable());
	//rectangle->setPosition(GetPosition().x, GetPosition().y);
	//rectangle->setFillColor(sf::Color(255,128,0));
	//return rectangle;
	sf::Sprite* sprite = dynamic_cast<sf::Sprite*>(GetDrawable());
	sprite->setPosition(GetPosition().x, GetPosition().y);
	return sprite;
}