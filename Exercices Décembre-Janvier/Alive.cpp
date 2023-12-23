#include "Alive.h"

Alive::Alive() : m_maxLife(1), m_life(m_maxLife){}

Alive::Alive(float a_maxLife) : m_maxLife(a_maxLife), m_life(m_maxLife){}

float Alive::GetMaxLife() {
	return m_maxLife;
}

float Alive::GetCurrentLife() {
	return m_life;
}

void Alive::TakeDamage(float a_damage) {
	m_life -= a_damage;
}

