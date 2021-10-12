#include "Field.h"

Field::Field(int x, int y) : x(x), y(y), organism(nullptr)
{
}

bool Field::isEmpty() const
{
	if (organism == nullptr)
		return true;
	return false;
}

void Field::setOrganism(Organism* org)
{
	organism = org;
}
