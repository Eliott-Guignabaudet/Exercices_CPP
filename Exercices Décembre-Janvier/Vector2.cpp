#include "Vector2.h"


Vector2::Vector2() : x(0), y(0){}

Vector2::Vector2(float a_x, float a_y) : x(a_x), y(a_y){}

Vector2 Vector2::Normalized() {
	Vector2 tmp;
	float magnitude = sqrt((x * x) + (y * y));
	tmp.x = x / magnitude;
	tmp.y = y / magnitude;
	return tmp;
}

float Vector2::GetDistance(Vector2 a_target) {
	return sqrtf((a_target.x - x) * (a_target.x - x) + (a_target.y - y) * (a_target.y - y));
}

Vector2 operator+(const Vector2& l, const Vector2& r) {
	Vector2 tmp(l);
	tmp += r;
	return tmp;
}

Vector2& Vector2::operator+=(const Vector2& r) {
	x += r.x;
	y += r.y;
	return *this;
}

Vector2 operator-(const Vector2& l, const Vector2& r) {
	Vector2 tmp(l);
	tmp -= r;
	return tmp;
}

Vector2& Vector2::operator-=(const Vector2& r) {
	x -= r.x;
	y -= r.y;
	return *this;
}

Vector2 operator*(const Vector2& l, const float& r) {
	Vector2 tmp(l);
	tmp *= r;
	return tmp;
}

Vector2& Vector2::operator*=(const float& r) {
	x *= r;
	y *= r;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector2& a_vector) {
	os << "(" << a_vector.x << ", " << a_vector.y << ")";
	return os;
}

