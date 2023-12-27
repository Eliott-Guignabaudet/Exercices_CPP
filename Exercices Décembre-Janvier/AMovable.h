#pragma once
#include "Vector2.h"
class AMovable
{
private:
	Vector2 m_direction;
	float m_speed;
public:
	AMovable();
	AMovable(Vector2 a_direction, float a_speed);

	Vector2 GetDirection();
	float GetSpeed();

	virtual void SetDirection(Vector2 a_direction);
	virtual void SetSpeed(float a_speed);

	virtual void Move() = 0;
	virtual void MoveToPosition(Vector2 a_targetPosition) = 0;
};

