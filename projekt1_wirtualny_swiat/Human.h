#pragma once
#include "Animal.h"
#include "Direction.h"
class Human : public Animal
{
public:
	Human(Field* field, World& world);
	void draw() const override;
	bool isImmortal() const { return immortality; }
	void activateImmortality();
	void deactivateImmortality();
	bool hasRunAway() const override;
	int getCountImmortality() const { return countImmortality; }
	void setCountImmortality(int value);
	virtual Organism* createNew(Field* field, World& world) const override;
private:
	bool immortality;
	int countImmortality;
};

