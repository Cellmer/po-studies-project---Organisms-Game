#include <iostream>
#include "Antelope.h"
#include "World.h"
#include "Field.h"

Antelope::Antelope(Field* field, World& world)
	: Animal(field, 4, 4, world)
{
	name = "Antelope";
}

void Antelope::action(Direction direction)
{
	Animal::action(chooseDirection());
	Animal::action(chooseDirection());
}

void Antelope::draw() const
{
	std::cout << "A";
}

bool Antelope::hasRunAway() const
{
	int random = rand() % 2;
	if (random == 0)
		return true;
	else
		return false;
}

void Antelope::run()
{
	Field* newField = world.findEmptyField(field);
	int fieldIndex = field->getPosY() * world.getWidth() + field->getPosX();
	if (newField)
	{
		if (field->getOrganism() == this)
		{
			field->setOrganism(nullptr);
		}
		newField->setOrganism(this);
		setField(newField);
	}
	else
	{
		Animal::action(chooseDirection());
	}
}

Organism* Antelope::createNew(Field* field, World& world) const
{
	return new Antelope(field, world);
}

