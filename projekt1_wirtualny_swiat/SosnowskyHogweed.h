#include "Plant.h"
class SosnowskyHogweed : public Plant
{
public:
	SosnowskyHogweed(Field* field, World& world);
	void draw() const override;
	void collision(Organism* attacker) override;
	void action(Direction direction) override;
	void killOne(Organism* attacked) const; //zabij
	void killAll() const; //zabij wszystkie zwierzêta naoko³o
	virtual Organism* createNew(Field* field, World& world) const override;
};