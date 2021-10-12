#include <cstdlib>
#include "Organism.h"
#include "World.h"
#include "Field.h"
#include "Direction.h"

Organism::Organism(Field* field, int strength, int initiative, World& world) 
	: field(field), strength(strength), initiative(initiative), world(world), dead(false), age(0)
{
}

void Organism::setField(Field* field)
{
	this->field = field;
}

Direction Organism::chooseDirection() const
{
	//losowanie kierunku ruchu organizmu
	int randDirection;
	if (field->getPosX() == 0) //organizm jest na lewej kraw�dzi
	{
		if (field->getPosY() == 0) //organizm jest w lewym g�rnym rogu
		{
			randDirection = rand() % 2;
			if (randDirection == 0)
				return RIGHT;
			else
				return DOWN;
		}
		else if (field->getPosY() == world.getHeight() - 1) //organizm jest w lewym dolnym rogu
		{
			randDirection = rand() % 2;
			if (randDirection == 0)
				return UP;
			else
				return RIGHT;
		}
		else //organizm jest gdzie� po �rodku lewej kraw�dzi
		{
			randDirection = rand() % 3;
			if (randDirection == 0)
				return UP;
			else if (randDirection == 1)
				return DOWN;
			else
				return RIGHT;
		}
	}
	else if (field->getPosX() == world.getWidth() - 1) //organizm jest na prawej kraw�dzi
	{
		if (field->getPosY() == 0) //organizm jest w prawym g�rnym rogu
		{
			randDirection = rand() % 2;
			if (randDirection == 0)
				return LEFT;
			else
				return DOWN;
		}
		else if (field->getPosY() == world.getHeight() - 1) //organizm jest w prawym dolnym rogu
		{
			randDirection = rand() % 2;
			if (randDirection == 0)
				return UP;
			else
				return LEFT;
		}
		else //organizm jest gdzie� po �rodku prawej kraw�dzi
		{
			randDirection = rand() % 3;
			if (randDirection == 0)
				return UP;
			else if (randDirection == 1)
				return LEFT;
			else
				return DOWN;
		}
	}
	else if (field->getPosY() == 0) //organizm jest gdzie� po �rodku g�rnej kraw�dzi
	{
		randDirection = rand() % 3;
		if (randDirection == 0)
			return LEFT;
		else if (randDirection == 1)
			return DOWN;
		else
			return RIGHT;
	}
	else if (field->getPosY() == world.getHeight() - 1) //organizm jest gdzie� po �rodku dolnej kraw�dzi
	{
		randDirection = rand() % 3;
		if (randDirection == 0)
			return LEFT;
		else if (randDirection == 1)
			return UP;
		else
			return RIGHT;
	}
	else //organizm jest gdzie� w �rodku planszy
	{
		randDirection = rand() % 4;
		if (randDirection == 0)
			return UP;
		else if (randDirection == 1)
			return DOWN;
		else if (randDirection == 2)
			return LEFT;
		else
			return RIGHT;
	}
}

bool Organism::isDead() const
{
	return dead;
}

void Organism::kill()
{
	dead = true;
}

void Organism::incrementAge()
{
	age++;
}

void Organism::decrementAge()
{
	age--;
}

void Organism::run()
{
	action(chooseDirection());
}

void Organism::increaseStrength(int points)
{
	strength += points;
}
