#pragma once
#include <SFML/System/Clock.hpp>
class GameTime
{
protected:
	static sf::Clock m_clock;
	static float m_deltaTime;
	static float m_totalTimeElapsed;
	static int m_targetFPS;
	
	virtual void Update() = 0;
	virtual void Draw() = 0;
public:
	static float GetDeltaTime();
	static float GetTotalTimeElapsed();

	virtual void Run() = 0;
};

