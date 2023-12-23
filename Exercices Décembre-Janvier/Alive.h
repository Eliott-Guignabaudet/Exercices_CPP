#pragma once
class Alive
{
private:
	float m_maxLife;
	float m_life;

public:
	Alive();
	Alive(float a_maxLife);

	virtual float GetMaxLife();
	virtual float GetCurrentLife();
	virtual void TakeDamage(float a_damage);
};

