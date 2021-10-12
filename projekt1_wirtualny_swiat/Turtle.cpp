#include <iostream>
#include "Turtle.h"

Turtle::Turtle(Field* field, World& world)
	: Animal(field, 2, 1, world)
{
	name = "Turtle";
}

void Turtle::draw() const
{
	std::cout << "T";
}

Direction Turtle::chooseDirection() const
{
	int random = rand() % 4;
	if (random <= 2)
		return NONE;
	return Organism::chooseDirection();
}

bool Turtle::defended(Organism* attacker) const
{
	if (attacker->getStrength() < 5)
		return true;
	return false;
}

Organism* Turtle::createNew(Field* field, World& world) const
{
	return new Turtle(field, world);
}
