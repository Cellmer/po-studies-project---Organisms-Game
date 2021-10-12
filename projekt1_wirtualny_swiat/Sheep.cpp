#include <iostream>
#include "Sheep.h"

Sheep::Sheep (Field* field, World& world)
	: Animal(field, 4, 4, world)
{
	name = "Sheep";
}

void Sheep::draw() const
{
	std::cout << "S";
}

Organism* Sheep::createNew(Field* field, World& world) const
{
	return new Sheep(field, world);
}
