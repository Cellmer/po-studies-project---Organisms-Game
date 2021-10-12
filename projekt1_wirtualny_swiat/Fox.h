#include "Animal.h"
class Fox : public Animal
{
public:
	Fox(Field* field, World& world);
	void draw() const override;
	Direction chooseDirection() const override;
	virtual Organism* createNew(Field* field, World& world) const override;
};