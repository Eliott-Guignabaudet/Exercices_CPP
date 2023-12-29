#pragma once
#include <SFML/Graphics.hpp>
#include "World.h"
class Manager
{
private:
	sf::RenderWindow* m_window;
	World* m_world;
	sf::View m_view;

	void Update();
	void Draw();
	void EventHandler();
public:
	Manager();
	void Run();
};

