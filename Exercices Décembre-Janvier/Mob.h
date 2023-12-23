#pragma once
#include "Entity.h"
#include "Alive.h"
#include "AMovable.h"
class Mob :
    public Entity,
    public Alive,
    public AMovable
{
private:
    void DisplayCreationMessage();
public:
    Mob();
    Mob(Vector2 a_position, float a_maxLife, Vector2 a_direction, float a_speed);

    virtual void TakeDamage(float a_damage) override;

    virtual void Move() override;
};

