#include "Animal.h"
class Turtle : public Animal
{
public:
	Turtle(Field* field, World& world);
	void draw() const override;
	Direction chooseDirection() const override;
	bool defended(Organism* attacker) const override;
	virtual Organism* createNew(Field* field, World& world) const override;
};