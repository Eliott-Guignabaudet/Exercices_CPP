#include "Player.h"

Player::Player() : Entity(), Alive(), AMovable(){
	DisplayCreationMessge();
}

Player::Player(Vector2 a_position, float a_maxLife, Vector2 a_direction, float a_speed) 
	: Entity(a_position), Alive(a_maxLife), AMovable(a_direction, a_speed){
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

void Player::ApplyDamage(Alive* a_target) {
	std::cout << "Player just attacked" << std::endl;
	a_target->TakeDamage(10);
}