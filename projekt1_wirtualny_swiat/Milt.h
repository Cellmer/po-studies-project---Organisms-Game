#include "Plant.h"
class Milt : public Plant
{
public:
	Milt(Field* field, World& world);
	void draw() const override;
	void action(Direction direction) override;
	virtual Organism* createNew(Field* field, World& world) const override;
};