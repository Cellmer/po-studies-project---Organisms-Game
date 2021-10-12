#include <iostream>
#include "Wolf.h"

Wolf::Wolf(Field* field, World& world)
	: Animal(field, 9, 5, world)
{
	name = "Wolf";
}

void Wolf::draw() const
{
	std::cout << "W";
}

Organism* Wolf::createNew(Field* field, World& world) const
{
	return new Wolf(field, world);
}
