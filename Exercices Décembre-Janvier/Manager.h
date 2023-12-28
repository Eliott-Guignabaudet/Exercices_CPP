#pragma once
#include <SFML/Graphics.hpp>
class Manager
{
private:
	sf::RenderWindow* m_window;
	void Update();
	void EventHandler();
public:
	Manager();
	void Run();
};

