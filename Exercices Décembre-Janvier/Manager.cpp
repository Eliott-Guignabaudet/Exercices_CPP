#include "Manager.h"

sf::Clock GameTime::m_clock = sf::Clock();
int GameTime::m_targetFPS = 60;

Manager::Manager() : m_world(nullptr), m_view(sf::View(sf::FloatRect(-25.f, -25.f, 50, 50))) {


	sf::RenderWindow*  window = new sf::RenderWindow(sf::VideoMode(800, 800), "My window");
	m_window = window;
	m_window->clear(sf::Color::Black);
	m_window->setView(m_view);
	if (!m_backGroundTexture.loadFromFile("Assets/ciel-etoile.jpg"))
	{
		return;
	}
}

void Manager::Run() {
	float previousTimeElapsed = 0;
	float clockDeltaTime = 0;
	m_world = new World();
	Draw();
	while (m_window->isOpen()) {

		m_totalTimeElapsed = m_clock.getElapsedTime().asSeconds();
		clockDeltaTime = m_totalTimeElapsed - previousTimeElapsed;
		previousTimeElapsed = m_totalTimeElapsed;

		m_deltaTime += clockDeltaTime;

		EventHandler();
		if (m_deltaTime >= 1.f/m_targetFPS)
		{
			Update();
			Draw();
			m_deltaTime = 0;
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
	else
	{
		m_world = new World();
	}

}

void Manager::Draw() {


	m_window->clear();

	sf::Sprite sprite;
	sf::Vector2u size = m_backGroundTexture.getSize();
	sprite.setTexture(m_backGroundTexture);
	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setScale(0.0125f, 0.0125f);
	m_window->draw(sprite);
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

		// Get Mouse position in view
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{

				sf::Vector2f mappedPosition = m_window->mapPixelToCoords(sf::Vector2i(sf::Mouse::getPosition(*m_window).x, sf::Mouse::getPosition(*m_window).y));
				m_world->SpawnMob(Vector2(mappedPosition.x, mappedPosition.y));
			}
		}
	}
}