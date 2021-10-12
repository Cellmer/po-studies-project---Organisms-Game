#pragma once
#include "Animal.h"
class Wolf : public Animal
{
public:
	Wolf(Field* field, World& world);
	void draw() const override;
	virtual Organism* createNew(Field* field, World& world) const override;
};

