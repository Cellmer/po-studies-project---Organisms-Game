#include "Plant.h"
class Grass : public Plant
{
public:
	Grass(Field* field, World& world);
	void draw() const override;
	virtual Organism* createNew(Field* field, World& world) const override;
};