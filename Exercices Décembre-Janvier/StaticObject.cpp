#include "StaticObject.h"

StaticObject::StaticObject() : Entity(){
	Load();
	DisplayCreationMessage();
}

StaticObject::StaticObject(Vector2 a_position) : Entity(a_position, new sf::Sprite()) {
	Load();
	DisplayCreationMessage();
}

void StaticObject::Load() {
	if (!p_texture.loadFromFile("Assets/Sprites/spaceStation_019.png"))
	{
		std::cout << "Texture don't load" << std::endl;
		return;
	}
	sf::Sprite* sprite = dynamic_cast<sf::Sprite*>(GetDrawable());
	sprite->setTexture(p_texture);
	sprite->setOrigin((p_texture.getSize().x / 2), (p_texture.getSize().y / 2));
	sprite->setScale(0.025f, 0.025f);


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
	/*sf::RectangleShape* rectangle = dynamic_cast<sf::RectangleShape*>(GetDrawable());
	rectangle->setFillColor(sf::Color(255,50,187));
	rectangle->setPosition(GetPosition().x, GetPosition().y);
	return rectangle;*/

	sf::Sprite* sprite = dynamic_cast<sf::Sprite*>(GetDrawable());
	sprite->setPosition(GetPosition().x, GetPosition().y);
	return sprite;
}