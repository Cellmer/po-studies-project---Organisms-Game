#pragma once
#include "Organism.h"
#include "Direction.h"
class Player;
class Animal : public Organism
{
public:
	Animal(Field* field, int strength, int initiative, World& world);
	virtual void action(Direction direction); //poruszanie
	virtual void collision(Organism* attacked); //walka lub rozmna¿anie
	virtual void draw() const = 0; //rysowanie na ekranie
	void procreate(Animal* partner);
	virtual Organism* createNew(Field* field, World& world) const = 0;
};

