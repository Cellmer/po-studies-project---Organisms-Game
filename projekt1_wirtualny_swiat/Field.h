#pragma once
class Organism;
class Field
{
public:
	Field(int x, int y);
	bool isEmpty() const;
	int getPosX() const { return x; }
	int getPosY() const { return y; }
	Organism* getOrganism() const { return organism; }
	void setOrganism(Organism* org);
private:
	int x;
	int y;
	Organism* organism;
};

