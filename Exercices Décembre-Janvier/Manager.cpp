#include "Manager.h"
Manager::Manager() : m_world(nullptr), m_view(sf::View(sf::FloatRect(-30.f, -30.f, 60.f, 60.f))) {

	sf::RenderWindow*  window = new sf::RenderWindow(sf::VideoMode(800, 800), "My window");
	m_window = window;
	m_window->setView(m_view);

}

void Manager::Run() {
	
	sf::Clock clock;
	m_world = new World();
	Draw();
	while (m_window->isOpen()) {
		sf::Time elapsedTime = clock.getElapsedTime();
		EventHandler();
		if (elapsedTime.asSeconds() > 1.f)
		{
			clock.restart();
			Update();
			Draw();
		}
	}
}

void Manager::Update(){
	if (m_world == nullptr)
	{
		return;
	}
	if (!m_world->CheckSimulationIsFinished())
	{
		m_world->Step();
	}

}

void Manager::Draw() {


	m_window->clear();
	/*sf::RectangleShape rectangele = sf::RectangleShape(sf::Vector2f(20.f,20.f));
	rectangele.setFillColor(sf::Color(255.f,255.f,255.f));
	m_window->draw(rectangele);
	m_window->display();*/

	std::vector<sf::Drawable*> drawables = m_world->Draw();
	for (int i = 0; i < drawables.size(); i++)
	{
		m_window->draw(*drawables[i]);
	}
	m_window->display();
	return;
}

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