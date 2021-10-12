#pragma once
#include <string>
#include "Direction.h"
class World;
class Field;
class Organism
{
public:
	Organism(Field* field, int strength, int initiative, World& world);
	virtual void action(Direction direction) = 0; //zachowanie
	virtual void collision(Organism* attacker) = 0; //zachowanie w przypadku kolizji
	virtual void draw() const = 0; //rysuje organizm na ekranie
	int getInitiative() const { return initiative; }
	int getStrength() const { return strength; }
	std::string getName() const { return name; }
	World& getWorld() const { return world; }
	Field* getField() const { return field; }
	void setField(Field* field);
	virtual Direction chooseDirection() const; //losuje kierunek ruchu organizmu
	virtual bool isDead() const;
	virtual void kill(); //ustawia atrybut dead na true
	int getAge() const { return age; }
	void incrementAge();
	void decrementAge();
	virtual bool hasRunAway() const { return false; }
	virtual void run();
	virtual bool defended(Organism* attacker) const { return false; }
	void increaseStrength(int points); //zwiêksz si³ê organizmu o points punktów
	virtual Organism* createNew(Field* field, World& world) const = 0; //zwraca nowostworzony organizm tego samego typu
protected:
	std::string name;
	int strength;
	int initiative;
	World& world; //referencja do œwiata w którym jest organizm
	Field* field; //wskaŸnik do pola na którym jest organizm
	bool dead;
	int age;
};

