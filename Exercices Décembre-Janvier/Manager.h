#pragma once
#include <SFML/Graphics.hpp>
#include "World.h"
#include "GameTime.h"
class Manager :
	public GameTime
{
private:
	sf::RenderWindow* m_window;
	World* m_world;
	sf::View m_view;

	void Update() override;
	void Draw() override;
	void EventHandler();
public:
	Manager();
	void Run() override;
};

