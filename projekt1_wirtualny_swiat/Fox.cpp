#include <iostream>
#include "Fox.h"
#include "Field.h"
#include "World.h"

Fox::Fox(Field* field, World& world)
	: Animal(field, 3, 7, world)
{
	name = "Fox";
}

void Fox::draw() const
{
	std::cout << "F";
}

Direction Fox::chooseDirection() const
{
	int fieldIndex =field->getPosY() * world.getWidth() + field->getPosX();
	int enemyStrenth = 0;
	if (field->getPosX() != 0) //lewo
	{
		if (world.getFields()[fieldIndex - 1]->isEmpty() || world.getFields()[fieldIndex - 1]->getOrganism()->getStrength() <= strength)
			return LEFT;
	}
	if (field->getPosX() != world.getWidth()-1) //prawo
	{
		if (world.getFields()[fieldIndex + 1]->isEmpty() || world.getFields()[fieldIndex + 1]->getOrganism()->getStrength() <= strength)
			return RIGHT;
	}
	if (field->getPosY() != 0) //góra
	{
		if (world.getFields()[fieldIndex - world.getWidth()]->isEmpty() || world.getFields()[fieldIndex - world.getWidth()]->getOrganism()->getStrength() <= strength)
			return UP;
	}
	if (field->getPosX() != world.getWidth()) //dó³
	{
		if (world.getFields()[fieldIndex + world.getWidth()]->isEmpty() || world.getFields()[fieldIndex + world.getWidth()]->getOrganism()->getStrength() <= strength)
			return DOWN;
	}

	return NONE;
}

Organism* Fox::createNew(Field* field, World& world) const
{
	return new Fox(field, world);
}
