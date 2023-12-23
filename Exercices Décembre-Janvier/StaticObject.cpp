#include "StaticObject.h"

StaticObject::StaticObject() : Entity(){
	DisplayCreationMessage();
}

StaticObject::StaticObject(Vector2 a_position) : Entity(a_position) {
	DisplayCreationMessage();
}

void StaticObject::DisplayCreationMessage() {
	std::cout
		<< "Static Object just created at x = "
		<< GetPosition().x
		<< " and y = "
		<< GetPosition().y
		<< std::endl;
}