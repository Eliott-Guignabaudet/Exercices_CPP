#include "Player.h"

Player::Player() : Entity(), Alive(), AMovable(){
	DisplayCreationMessge();
}

Player::Player(Vector2 a_position, float a_maxLife, Vector2 a_direction, float a_speed) 
	: Entity(a_position, new sf::CircleShape(1.f)), Alive(a_maxLife), AMovable(a_direction, a_speed){
	DisplayCreationMessge();
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
	SetPosition(GetPosition() + (GetDirection() * GetSpeed()));
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
		SetSpeed(distance);
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
	sf::CircleShape* circle = dynamic_cast<sf::CircleShape*>(GetDrawable());
	circle->setPosition(GetPosition().x, GetPosition().y);
	circle->setFillColor(sf::Color(255, 255, 0));
	return circle;
}