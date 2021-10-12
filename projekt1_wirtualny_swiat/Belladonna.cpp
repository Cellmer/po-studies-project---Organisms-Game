#include <iostream>
#include "Belladonna.h"
#include "Field.h"

Belladonna::Belladonna(Field* field, World& world)
	: Plant(field, 99, world)
{
	name = "Belladonna";
}

void Belladonna::draw() const
{
	std::cout << "B";
}

void Belladonna::collision(Organism* attacker)
{
		if (attacker->hasRunAway()) //atakuj¹cy uciek³
		{
			//ustawia pole, na któym by³ organizm jako puste, chyba ¿e organizm jest w trakcie ucieczki
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
			//ustawia pole, na któym by³ organizm jako puste, chyba ¿e organizm jest w trakcie ucieczki
			if (attacker->getField()->getOrganism() == attacker)
			{
				attacker->getField()->setOrganism(nullptr);
			}
			std::cout << attacker->getName() << " dies after eating " << name << std::endl;
			attacker->kill();
		}
}

Organism* Belladonna::createNew(Field* field, World& world) const
{
	return new Belladonna(field, world);
}
