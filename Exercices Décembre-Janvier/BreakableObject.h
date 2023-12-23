#pragma once
#include "Entity.h"
#include "Alive.h"
class BreakableObject :
    public Entity, 
    public Alive
{
private:
    void DisplayCreationMessage();
    void DisplayBrokeMessage();
public:
    BreakableObject();
    BreakableObject(Vector2 a_position, float a_maxLife);

    virtual void TakeDamage(float a_damage) override;
};

