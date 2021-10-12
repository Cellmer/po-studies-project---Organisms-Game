#pragma once
#include "Animal.h"
class Sheep : public Animal
{
public:
	Sheep(Field* field, World& world);
	void draw() const override;
	virtual Organism* createNew(Field* field, World& world) const override;
};

