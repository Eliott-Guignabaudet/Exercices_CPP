#include "AMovable.h"

AMovable::AMovable() : m_direction(Vector2()), m_speed(0){}

AMovable::AMovable(Vector2 a_direction, float a_speed) : m_direction(a_direction.Normalized()), m_speed(a_speed){}

Vector2 AMovable::GetDirection() {
	return m_direction;
}

float AMovable::GetSpeed() {
	return m_speed;
}

void AMovable::SetDirection(Vector2 a_direction) {
	m_direction = a_direction.Normalized();
}

void AMovable::SetSpeed(float a_speed) {
	m_speed = a_speed;
} 
