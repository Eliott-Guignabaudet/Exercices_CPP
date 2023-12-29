#pragma once
#include "Entity.h"
class StaticObject :
    public Entity
{
private:
    void DisplayCreationMessage();
public:
    StaticObject();
    StaticObject(Vector2 a_position);
    sf::Drawable* Draw() override;
};

