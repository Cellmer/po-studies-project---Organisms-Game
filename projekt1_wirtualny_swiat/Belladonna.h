#include "Plant.h"
class Belladonna : public Plant
{
public:
	Belladonna(Field* field, World& world);
	void draw() const override;
	void collision(Organism* attacker) override;
	virtual Organism* createNew(Field* field, World& world) const override;
};