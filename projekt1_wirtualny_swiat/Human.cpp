#include <iostream>
#include "Human.h"
#include "Animal.h"
#include "Field.h"
#include "World.h"

Human::Human(Field* field, World& world)
	: Animal(field, 5, 4, world )
{
	name = "Human";
	immortality = false;
	countImmortality = 0;
}

void Human::draw() const
{
	std::cout << "H";
}

void Human::activateImmortality()
{
	immortality = true;
}

void Human::deactivateImmortality()
{
	immortality = false;
}

bool Human::hasRunAway() const
{
	if (immortality == true)
		return true;
	return false;
}

void Human::setCountImmortality(int value)
{
	countImmortality = value;
}

Organism* Human::createNew(Field* field, World& world) const
{
	return new Human(field, world);
}
