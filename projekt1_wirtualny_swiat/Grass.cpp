#include <iostream>
#include "Grass.h"

Grass::Grass(Field* field, World& world)
	: Plant(field, 0, world)
{
	name = "Grass";
}

void Grass::draw() const
{
	std::cout << "G";
}

Organism* Grass::createNew(Field* field, World& world) const
{
	return new Grass(field, world);
}
