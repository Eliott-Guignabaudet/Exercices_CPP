#include "Manager.h"
Manager::Manager() {

	sf::RenderWindow*  window = new sf::RenderWindow(sf::VideoMode(800, 600), "My window");
	m_window = window;
}

void Manager::Run() {
	

	
	while (m_window->isOpen()) {
		EventHandler();
	}
}

void Manager::Update(){}

void Manager::EventHandler() {
	sf::Event event;
	while (m_window->pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed) {
			m_window->close();
		}
	}
}