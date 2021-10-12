#include <iostream>
#include "Field.h"
#include "SosnowskyHogweed.h"
#include "World.h"
#include "Animal.h"

SosnowskyHogweed::SosnowskyHogweed(Field* field, World& world)
	: Plant(field, 10, world)
{
	name = "SosnowskyHogweed";
}

void SosnowskyHogweed::draw() const
{
	std::cout << "@";
}

void SosnowskyHogweed::collision(Organism* attacker)
{
	if (attacker->hasRunAway()) //atakuj�cy uciek�
	{
		//ustawia pole, na kt�ym by� organizm jako puste, chyba �e organizm jest w trakcie ucieczki
		if (attacker->getField()->getOrganism() == attacker)
		{
			attacker->getField()->setOrganism(nullptr);
		}
		attacker->setField(field);
		std::cout << attacker->getName() << " has run away from a " << name << std::endl;
		attacker->run();
	}
	else
	{
		Plant::collision(attacker);
		//ustawia pole, na kt�ym by� organizm jako puste, chyba �e organizm jest w trakcie ucieczki
		if (attacker->getField()->getOrganism() == attacker)
		{
			attacker->getField()->setOrganism(nullptr);
		}
		std::cout << attacker->getName() << " dies after eating " << name << std::endl;
		attacker->kill();
	}
}

void SosnowskyHogweed::action(Direction direction)
{
	killAll();
	Plant::action(direction);
	
}

void SosnowskyHogweed::killOne(Organism* attacked) const
{
	if (attacked->hasRunAway()) //atakowany uciek�
	{
		//attacked->getField()->setOrganism(nullptr);
		//attacked->setField(field);
		std::cout << attacked->getName() << " has run away from a " << name << std::endl;
		attacked->run();
	}
	else
	{
		attacked->getField()->setOrganism(nullptr);
		std::cout << attacked->getName() << " dies in confrontation with " << name << std::endl;
		attacked->kill();
	}
}

void SosnowskyHogweed::killAll() const
{
	//zabij wszsytkie zwierz�ta naoko�o
	int fieldIndex = field->getPosY() * world.getWidth() + field->getPosX();
	if (field->getPosX() != 0)
	{
		if (!world.getFields()[fieldIndex - 1]->isEmpty()) //pole na lewo
			if (dynamic_cast<Animal*>(world.getFields()[fieldIndex - 1]->getOrganism()))
				killOne(world.getFields()[fieldIndex - 1]->getOrganism());

		if (field->getPosY() != 0 && !world.getFields()[fieldIndex - world.getWidth() - 1]->isEmpty()) //g�rny lewy r�g
			if (dynamic_cast<Animal*>(world.getFields()[fieldIndex - world.getWidth() - 1]->getOrganism()))
				killOne(world.getFields()[fieldIndex - world.getWidth() - 1]->getOrganism());

		if (field->getPosY() != world.getHeight() - 1 && !world.getFields()[fieldIndex + world.getWidth() - 1]->isEmpty()) //dolny lewy r�g
			if (dynamic_cast<Animal*>(world.getFields()[fieldIndex + world.getWidth() - 1]->getOrganism()))
				killOne(world.getFields()[fieldIndex + world.getWidth() - 1]->getOrganism());
	}
	if (field->getPosX() != world.getWidth() - 1)
	{
		if (!world.getFields()[fieldIndex + 1]->isEmpty()) //pole na prawo
			if (dynamic_cast<Animal*>(world.getFields()[fieldIndex + 1]->getOrganism()))
				killOne(world.getFields()[fieldIndex + 1]->getOrganism());

		if (field->getPosY() != 0 && !world.getFields()[fieldIndex - world.getWidth() + 1]->isEmpty()) //g�rny prawy r�g
			if (dynamic_cast<Animal*>(world.getFields()[fieldIndex - world.getWidth() + 1]->getOrganism()))
				killOne(world.getFields()[fieldIndex - world.getWidth() + 1]->getOrganism());

		if (field->getPosY() != world.getHeight() - 1 && !world.getFields()[fieldIndex + world.getWidth() + 1]->isEmpty()) //dolny prawy r�g
			if (dynamic_cast<Animal*>(world.getFields()[fieldIndex + world.getWidth() + 1]->getOrganism()))
				killOne(world.getFields()[fieldIndex + world.getWidth() + 1]->getOrganism());
	}
	if (field->getPosY() != 0 && !world.getFields()[fieldIndex - world.getWidth()]->isEmpty()) //pole w g�r�
		if (dynamic_cast<Animal*>(world.getFields()[fieldIndex - world.getWidth()]->getOrganism()))
			killOne(world.getFields()[fieldIndex - world.getWidth()]->getOrganism());

	if (field->getPosY() != world.getHeight() - 1 && !world.getFields()[fieldIndex + world.getWidth()]->isEmpty()) //pole w d�l
		if (dynamic_cast<Animal*>(world.getFields()[fieldIndex + world.getWidth()]->getOrganism()))
			killOne(world.getFields()[fieldIndex + world.getWidth()]->getOrganism());
}

Organism* SosnowskyHogweed::createNew(Field* field, World& world) const
{
	return new SosnowskyHogweed(field, world);
}
