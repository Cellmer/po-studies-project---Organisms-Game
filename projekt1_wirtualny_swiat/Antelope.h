#include "Animal.h"
class Antelope : public Animal
{
public:
	Antelope(Field* field, World& world);
	void action(Direction direction) override; //podwójny ruch
	void draw() const override;
	bool hasRunAway() const override;
	void run() override;
	virtual Organism* createNew(Field* field, World& world) const override;
};