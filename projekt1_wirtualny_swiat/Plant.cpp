#include <iostream>
#include "Plant.h"
#include "World.h"
#include "Field.h"
#include "Grass.h"
#include "Milt.h"
#include "Guarana.h"
#include "Belladonna.h"
#include "SosnowskyHogweed.h"

Plant::Plant(Field* field, int strength, World& world)
	: Organism(field, strength, 0, world)
{
}

void Plant::action(Direction direction)
{
	//std::cout << name << " on position " << field->getPosX() << ", " << field->getPosY();
	int fieldIndex = field->getPosY() * world.getWidth() + field->getPosX();
	Field* newField;
	switch (direction)
	{
	case UP:
		newField = world.getFields()[fieldIndex - world.getWidth()];

		if (newField->isEmpty())
		{
			seed(this, newField);
			std::cout << name << " on position " << field->getPosX() << ", " << field->getPosY();
			std::cout << " seeded up\n";
		}
		/*else
			std::cout << " did nothing\n";*/
		break;

	case DOWN:
		newField = world.getFields()[fieldIndex + world.getWidth()];

		if (newField->isEmpty())
		{
			seed(this, newField);
			std::cout << name << " on position " << field->getPosX() << ", " << field->getPosY();
			std::cout << " seeded down\n";
		}
		/*else
			std::cout << " did nothing\n";*/
		break;

	case LEFT:
		newField = world.getFields()[fieldIndex - 1];

		if (newField->isEmpty())
		{
			seed(this, newField);
			std::cout << name << " on position " << field->getPosX() << ", " << field->getPosY();
			std::cout << " seeded left\n";
		}
		/*else
			std::cout << " did nothing\n";*/
		break;

	case RIGHT:
		newField = world.getFields()[fieldIndex + 1];

		if (newField->isEmpty())
		{
			seed(this, newField);
			std::cout << name << " on position " << field->getPosX() << ", " << field->getPosY();
			std::cout << " seeded right\n";
		}
		/*else
			std::cout << " did nothing\n";*/
		break;

	/*case NONE:
		std::cout << " did nothing\n";*/
	}
}

void Plant::collision(Organism* attacker)
{
	//zwierzê zjada roœlinê
	//ustawia pole, na któym by³ organizm jako puste, chyba ¿e organizm jest w trakcie ucieczki
	if (attacker->getField()->getOrganism() == attacker)
	{
		attacker->getField()->setOrganism(nullptr);
	}
	attacker->setField(field);
	field->setOrganism(attacker);
	std::cout << attacker->getName() << " ate a " << name << std::endl;
	kill();
}

Direction Plant::chooseDirection() const
{
	int random = rand() % 100;
	if (random < 5)
		return Organism::chooseDirection();
	return NONE;
}

void Plant::seed(Plant* plant, Field* field) const
{
	Plant* newPlant = dynamic_cast<Plant*>(createNew(field,world));

	newPlant->setField(field);
	field->setOrganism(newPlant);
	world.addOrganism(newPlant);
	newPlant->decrementAge();
}
