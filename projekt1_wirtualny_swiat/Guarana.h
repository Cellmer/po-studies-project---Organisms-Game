#include "Plant.h"
class Guarana : public Plant
{
public:
	Guarana(Field* field, World& world);
	void draw() const override;
	void collision(Organism* attacker) override;
	virtual Organism* createNew(Field* field, World& world) const override;
};