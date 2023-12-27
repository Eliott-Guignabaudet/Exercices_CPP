#pragma once
#include <iostream>

class Vector2
{
public:
	float x;
	float y;

	Vector2();
	Vector2(float a_x, float a_y);

	Vector2 Normalized();
	float GetDistance(Vector2 a_target);

	Vector2& operator+=(const Vector2& r);
	Vector2& operator-=(const Vector2& r);
	Vector2& operator*=(const float& r);

	friend std::ostream& operator<<(std::ostream& os, const Vector2& a_vector);

};

Vector2 operator+(const Vector2& l, const Vector2& r);
Vector2 operator-(const Vector2& l, const Vector2& r);
Vector2 operator*(const Vector2& l, const float& r);

