#include "Player.h"
#include "GameTime.h"
Player::Player() : Entity(), Alive(), AMovable(){
	Load();
	DisplayCreationMessge();
}

Player::Player(Vector2 a_position, float a_maxLife, Vector2 a_direction, float a_speed) 
	: Entity(a_position, new sf::Sprite()), Alive(a_maxLife), AMovable(a_direction, a_speed){
	Load();
	DisplayCreationMessge();
}

void Player::Load() {
	if (!p_texture.loadFromFile("Assets/Sprites/spaceShips_001.png"))
	{
		std::cout << "Texture don't load" << std::endl;
		return;
	}
	sf::Sprite* sprite = dynamic_cast<sf::Sprite*>(GetDrawable());
	sprite->setTexture(p_texture);
	sprite->setScale(0.025f, 0.025f);
}

void Player::DisplayCreationMessge() {
	std::cout
		<< "Player just created at x = "
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

void Player::TakeDamage(float a_damage) {
	Alive::TakeDamage(a_damage);
	if (GetCurrentLife() <= 0)
	{
		std::cout << "Player just died" << std::endl;
	}
}

void Player::Move() {
	SetPosition(GetPosition() + (GetDirection() * GetSpeed() * GameTime::GetDeltaTime()));
	std::cout
		<< "Player moved to x = "
		<< GetPosition().x
		<< " and y = "
		<< GetPosition().y
		<< std::endl;
}

void Player::MoveToPosition(Vector2 a_targetPosition) {
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

void Player::ApplyDamage(Alive* a_target) {
	std::cout << "Player just attacked" << std::endl;
	a_target->TakeDamage(10);
}

void Player::StepToEnnemy(Alive* a_target, Vector2 a_targetPosition) {
	MoveToPosition(a_targetPosition);
	float distance = GetPosition().GetDistance(a_targetPosition);
	if (distance < 1)
	{
		ApplyDamage(a_target);
	}
}

sf::Drawable* Player::Draw() {
	/*sf::CircleShape* circle = dynamic_cast<sf::CircleShape*>(GetDrawable());
	circle->setPosition(GetPosition().x, GetPosition().y);
	circle->setFillColor(sf::Color(255, 255, 0));
	return circle;*/
	sf::Sprite* sprite = dynamic_cast<sf::Sprite*>(GetDrawable());
	sprite->setPosition(GetPosition().x, GetPosition().y);
	return sprite;

}