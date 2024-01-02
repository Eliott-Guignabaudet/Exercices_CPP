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
    void Load();
public:
    BreakableObject();
    BreakableObject(Vector2 a_position, float a_maxLife);
    sf::Drawable* Draw() override;
    virtual void TakeDamage(float a_damage) override;
};

