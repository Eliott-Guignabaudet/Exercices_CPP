#define _USE_MATH_DEFINES
#include "Mob.h"
#include "GameTime.h"
#include <math.h>
Mob::Mob() 
	: Entity(), Alive(), AMovable(){
	Load();
	DisplayCreationMessage();
}
Mob::Mob(Vector2 a_position, float a_maxLife, Vector2 a_direction, float a_speed) 
	: Entity(a_position, new sf::Sprite()), Alive(a_maxLife), AMovable(a_direction, a_speed){
	Load();
	DisplayCreationMessage();
}

void Mob::Load() {
	if (!p_texture.loadFromFile("Assets/Sprites/spaceAstronauts_005.png"))
	{
		std::cout << "Texture don't load" << std::endl;
		return;
	}
	sf::Sprite* sprite = dynamic_cast<sf::Sprite*>(GetDrawable());
	sprite->setTexture(p_texture);
	sprite->setOrigin((p_texture.getSize().x / 2), (p_texture.getSize().y / 2));
	sprite->setScale(0.05f, 0.05f);

}

void Mob::DisplayCreationMessage(){
	std::cout
		<< "Mob just created at x = "
		<< GetPosition().x
		<< " and y = "
		<< GetPosition().y
		<< " with "
		<< GetMaxLife()
		<< " life with direction x = "
		<< GetDirection().x
		<< " and y = "
		<< GetDirection().y
		<< std::endl;
}

void Mob::TakeDamage(float a_damage){
	Alive::TakeDamage(a_damage);
	if (GetCurrentLife() <= 0)
	{
		std::cout << "Mob just die" << std::endl;
	}
}

void Mob::Move() {
	SetPosition(GetPosition() + (GetDirection() * GetSpeed() * GameTime::GetDeltaTime()));
	/*std::cout
		<< "Mob move to x = "
		<< GetPosition().x
		<< " and y = "
		<< GetPosition().y
		<< std::endl;*/
}

void Mob::MoveToPosition(Vector2 a_targetPosition) {
	SetDirection(a_targetPosition - GetPosition());
	float distance = GetPosition().GetDistance(a_targetPosition);
	if (distance < GetSpeed())
	{
		float tmpSpeed = GetSpeed();
		//SetSpeed(distance);
		Move();
		SetSpeed(tmpSpeed);
	}
	else
	{
		Move();
	}
}

sf::Drawable* Mob::Draw() {
	/*sf::CircleShape* circle = dynamic_cast<sf::CircleShape*>(GetDrawable());
	circle->setPosition(GetPosition().x, GetPosition().y);
	circle->setFillColor(sf::Color(0, 0, 255));
	return circle;*/

	sf::Sprite* sprite = dynamic_cast<sf::Sprite*>(GetDrawable());
	sprite->setPosition(GetPosition().x, GetPosition().y);
	sprite->setRotation((std::atan2(GetDirection().y, GetDirection().x) * 180 / M_PI) );

	return sprite;
}