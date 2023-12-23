#include <iostream>
#include "StaticObject.h"
#include "BreakableObject.h"
#include "Mob.h"
#include "Player.h"

using namespace std;
int main() {
	std::cout << "Hello World" << std::endl;
	
	StaticObject *staticObject = new StaticObject(Vector2(10, 10));
	BreakableObject *tower = new BreakableObject(Vector2(-5, -12), 50);

	Mob *zombi = new Mob(Vector2(5, 5), 30, Vector2(1, 4), 2);
	Player *player = new Player(Vector2(0, 0), 20, Vector2(1, 0), 5);

	cout << endl;

	player->Move();
	cout << player->GetPosition() << endl << endl;
	zombi->Move();
	cout << zombi->GetPosition() << endl << endl;

	cout << zombi->GetCurrentLife() << endl;
	player->ApplyDamage(zombi);
	player->ApplyDamage(zombi);
	player->ApplyDamage(zombi);

	cout << zombi->GetCurrentLife() << endl << endl;

	cout << tower->GetCurrentLife() << endl;
	player->ApplyDamage(tower);
	player->ApplyDamage(tower);
	player->ApplyDamage(tower);
	cout << tower->GetCurrentLife() << endl;
	player->ApplyDamage(tower);
	player->ApplyDamage(tower);
	cout << tower->GetCurrentLife() << endl;




} 