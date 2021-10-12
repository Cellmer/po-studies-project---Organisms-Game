#include <iostream>
#include <vector>
#include "World.h"
#include "Organism.h"
#include "Animal.h"
#include "Field.h"
#include "Direction.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"

Animal::Animal(Field* field, int strength, int initiative, World& world)
	: Organism(field, strength, initiative, world)
{
}

void Animal::action(Direction direction)
{
	std::cout << name << " on position " << field->getPosX() << ", " << field->getPosY();
	int fieldIndex = field->getPosY() * world.getWidth() + field->getPosX();
	Field* newField;
	switch (direction)
	{
	case UP:
		std::cout << " moved up.\n";
		newField = world.getFields()[fieldIndex - world.getWidth()];

		if (newField->isEmpty())
		{
			//ustawia pole, na któym by³ organizm jako puste, chyba ¿e organizm jest w trakcie ucieczki
			if (field->getOrganism() == this)
			{
				field->setOrganism(nullptr);
			}
			newField->setOrganism(this);
			setField(newField);
		}
		else
		{
			newField->getOrganism()->collision(this);
		}
		break;

	case DOWN:
		std::cout << " moved down.\n";
		newField = world.getFields()[fieldIndex + world.getWidth()];

		if (newField->isEmpty())
		{
			//ustawia pole, na któym by³ organizm jako puste, chyba ¿e organizm jest w trakcie ucieczki
			if (field->getOrganism() == this)
			{
				field->setOrganism(nullptr);
			}
			newField->setOrganism(this);
			setField(newField);
		}
		else
		{
			newField->getOrganism()->collision(this);
		}
		break;

	case LEFT:
		std::cout << " moved left.\n";
		newField = world.getFields()[fieldIndex - 1];

		if (newField->isEmpty())
		{
			//ustawia pole, na któym by³ organizm jako puste, chyba ¿e organizm jest w trakcie ucieczki
			if (field->getOrganism() == this)
			{
				field->setOrganism(nullptr);
			}
			newField->setOrganism(this);
			setField(newField);
		}
		else
		{
			newField->getOrganism()->collision(this);
		}
		break;

	case RIGHT:
		std::cout << " moved right.\n";
		newField = world.getFields()[fieldIndex + 1];

		if (newField->isEmpty())
		{
			//ustawia pole, na któym by³ organizm jako puste, chyba ¿e organizm jest w trakcie ucieczki
			if (field->getOrganism() == this)
			{
				field->setOrganism(nullptr);
			}
			newField->setOrganism(this);
			setField(newField);
		}
		else
		{
			newField->getOrganism()->collision(this);
		}
		break;

	case NONE:
		std::cout << " stayed at his place\n";
		break;
	}
}

void Animal::collision(Organism* attacker)
{
	if (name == attacker->getName())
	{
		procreate(dynamic_cast<Animal*>(attacker));
	}
	else
	{
		if (defended(attacker)) //atakowany odbi³ atak
		{
			std::cout << name << " defended himself from a " << attacker->getName() << std::endl;
		}
		else if (attacker->getStrength() >= strength) //atakuj¹cy wygrywa walkê
		{
			//ustawia pole, na któym by³ organizm jako puste, chyba ¿e organizm jest w trakcie ucieczki
			if (attacker->getField()->getOrganism() == attacker)
			{
				attacker->getField()->setOrganism(nullptr);
			}
			attacker->setField(field);
			field->setOrganism(attacker);

			if (hasRunAway()) //atakowany uciek³
			{
				std::cout << name << " has run away from a " << attacker->getName() << std::endl;
				run();
			}
			else
			{
				std::cout << attacker->getName() << " killed a " << name << std::endl;
				kill();
			}
		}
		else //atakowany wygrywa walkê
		{
			//ustawia pole, na któym by³ organizm jako puste, chyba ¿e organizm jest w trakcie ucieczki
			if (attacker->getField()->getOrganism() == attacker)
			{
				attacker->getField()->setOrganism(nullptr);
			}

			if (attacker->hasRunAway()) //atakuj¹cy uciek³
			{
				attacker->setField(field);
				std::cout << attacker->getName() << " has run away from a " << name << std::endl;
				attacker->run();
			}
			else
			{
				std::cout << name << " killed a " << attacker->getName() << std::endl;
				attacker->kill();
			}
		}
	}
}

void Animal::procreate(Animal* partner)
{
	if (age>=0 && partner->getAge() >= 0) //nowonarodzone dzieci nie mog¹ mieæ dzieci
	{
		Field* newField = world.findEmptyField(field);
		if (!newField) //nie znaleziono pustych pól naoko³o pierwszego organizmu
			newField = world.findEmptyField(partner->getField());
		if (newField)
		{
			Animal* newAnimal = dynamic_cast<Animal*>(createNew(newField, world));

			newAnimal->decrementAge();
			world.addOrganism(newAnimal);
			newField->setOrganism(world.getOrganisms().back());
			std::cout << name << " gave birth to a " << name << "!\n";
		}
		else
		{
			std::cout << name << " tried to gave birth to a child but there was no place for that!\n";
		}
	}

}
