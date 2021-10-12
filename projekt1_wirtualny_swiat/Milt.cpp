#include <iostream>
#include "Milt.h"

Milt::Milt(Field* field, World& world)
	: Plant(field, 0, world)
{
	name = "Milt";
}

void Milt::draw() const
{
	std::cout << "M";
}

void Milt::action(Direction direction)
{
	for (int i = 0; i < 3; i++)
	{
		Plant::action(chooseDirection());
	}
}

Organism* Milt::createNew(Field* field, World& world) const
{
	return new Milt(field, world);
}
