#pragma once
#include "Organism.h"
class Plant : public Organism
{
public:
	Plant(Field* field, int strength, World& world);
	virtual void action(Direction direction); //rozprzestrzenianie
	virtual void collision(Organism* attacker);
	virtual Direction chooseDirection() const;
	void seed(Plant* plant, Field* field) const; //zasiej roœlinê plant na polu field
	virtual Organism* createNew(Field* field, World& world) const = 0;
};

