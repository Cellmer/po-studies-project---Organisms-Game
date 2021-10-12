#include <iostream>
#include "Guarana.h"

Guarana::Guarana(Field* field, World& world)
	: Plant(field, 0, world)
{
	name = "Guarana";
}

void Guarana::draw() const
{
	std::cout << "+";
}

void Guarana::collision(Organism* attacker)
{
	Plant::collision(attacker);
	attacker->increaseStrength(3);
	std::cout << attacker->getName() << "'s strength increased to " << attacker->getStrength() << " after eating " << name << "!\n";
}

Organism* Guarana::createNew(Field* field, World& world) const
{
	return new Guarana(field, world);
}
