#include <iostream>
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "BreakableObject.h"
#include "Mob.h"
#include "Player.h"
#include "World.h"
#include "Manager.h"

using namespace std;
int main() {
	std::cout << "Hello World" << std::endl;

	/*World *world = new World();
	while (!world->CheckSimulationIsFinished())
	{
		world->Step();
	}

	delete world;*/

    Manager* manager = new Manager();
    manager->Run();
} 