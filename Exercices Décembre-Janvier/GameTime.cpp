#include "GameTime.h"

float GameTime::m_deltaTime;
float GameTime::m_totalTimeElapsed ;

float GameTime::GetDeltaTime() {
	return GameTime::m_deltaTime;
}

float GameTime::GetTotalTimeElapsed() {
	return GameTime::m_totalTimeElapsed;
}