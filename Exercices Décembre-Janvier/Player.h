#pragma once
#include "Entity.h"
#include "Alive.h"
#include "AMovable.h"
#include "IAttacker.h"
class Player : 
    public Entity,
    public Alive,
    public AMovable,
    public IAttacker
{ 
private:
    void DisplayCreationMessge();
public:
    Player();
    Player(Vector2 a_position, float a_maxLife, Vector2 a_direction, float a_speed);

    virtual void TakeDamage(float a_damage) override;
    virtual void Move() override;
    virtual void MoveToPosition(Vector2 a_targetPosition) override;
    virtual void ApplyDamage(Alive* a_target) override;

    void StepToEnnemy(Alive* a_target, Vector2 a_targetPosition);

    sf::Drawable* Draw() override;

};

