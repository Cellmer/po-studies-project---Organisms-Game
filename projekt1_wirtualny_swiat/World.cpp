#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "World.h"
#include "Human.h"
#include "Wolf.h"
#include "Field.h"
#include "Organism.h"
#include "Direction.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Grass.h"
#include "Milt.h"
#include "Guarana.h"
#include "Belladonna.h"
#include "SosnowskyHogweed.h"

World::World(int w, int h, Human** player)
	: width(w), height(h)
{
	std::vector<Field*> emptyFields; //wektor sk³adaj¹cy siê tylko z pustych pól
	fields.reserve(width * height);
	emptyFields.reserve(width * height);
	for (int i = 0; i < height; i++) //ustaw wspó³rzêdne pól
	{
		for (int j = 0; j < width; j++)
		{
			fields.emplace_back(new Field(j, i));
			emptyFields.emplace_back(new Field(j, i));
		}
	}

	const int instancesNumber = 3; //pocz¹tkowa liczba przedstawicieli jednego gatunku (ka¿dego oprócz cz³owieka jest tyle samo na starcie)
	const int speciesNumber = 10; //liczba gatunków organizmów (poza cz³owiekiem)
	organisms.reserve(instancesNumber * speciesNumber + 1); //rezerwuje miejsce w wektorze na wszystkie pocz¹tkowe organizmy

	//losowanie pocz¹tkowych pozycji wszystkich organizmów
	std::srand(std::time(nullptr));

	//pozycja cz³owieka
	int randomIndex = std::rand()%emptyFields.size();
	int fieldIndex = randomIndex;
	organisms.emplace_back(new Human(fields[fieldIndex], *this));
	(*player) = dynamic_cast<Human*>(organisms.back());
	fields[fieldIndex]->setOrganism(organisms.back());
	emptyFields.erase(emptyFields.begin()+randomIndex);

	std::cout << organisms.back()->getName() << ": "; 	//wyœwietlenie legendy na pocz¹tku gry
	organisms.back()->draw();
	std::cout << std::endl;

	//pozycja wilków
	for (int i = 0; i < instancesNumber; i++)
	{
		int randomIndex = std::rand() % emptyFields.size();
		fieldIndex = emptyFields[randomIndex]->getPosY() * width + emptyFields[randomIndex]->getPosX();
		organisms.emplace_back(new Wolf(fields[fieldIndex], *this));
		fields[fieldIndex]->setOrganism(organisms.back());
		emptyFields.erase(emptyFields.begin() + randomIndex);
	}
	std::cout << organisms.back()->getName() << ": ";
	organisms.back()->draw();
	std::cout << std::endl;

	//pozycja owiec
	for (int i = 0; i < instancesNumber; i++)
	{
		int randomIndex = std::rand() % emptyFields.size();
		fieldIndex = emptyFields[randomIndex]->getPosY() * width + emptyFields[randomIndex]->getPosX();
		organisms.emplace_back(new Sheep(fields[fieldIndex], *this));
		fields[fieldIndex]->setOrganism(organisms.back());
		emptyFields.erase(emptyFields.begin() + randomIndex);
	}
	std::cout << organisms.back()->getName() << ": ";
	organisms.back()->draw();
	std::cout << std::endl;

	//pozycja lisów
	for (int i = 0; i < instancesNumber; i++)
	{
		int randomIndex = std::rand() % emptyFields.size();
		fieldIndex = emptyFields[randomIndex]->getPosY() * width + emptyFields[randomIndex]->getPosX();
		organisms.emplace_back(new Fox(fields[fieldIndex], *this));
		fields[fieldIndex]->setOrganism(organisms.back());
		emptyFields.erase(emptyFields.begin() + randomIndex);
	}
	std::cout << organisms.back()->getName() << ": ";
	organisms.back()->draw();
	std::cout << std::endl;

	//pozycja ¿ó³wi
	for (int i = 0; i < instancesNumber; i++)
	{
		int randomIndex = std::rand() % emptyFields.size();
		fieldIndex = emptyFields[randomIndex]->getPosY() * width + emptyFields[randomIndex]->getPosX();
		organisms.emplace_back(new Turtle(fields[fieldIndex], *this));
		fields[fieldIndex]->setOrganism(organisms.back());
		emptyFields.erase(emptyFields.begin() + randomIndex);
	}
	std::cout << organisms.back()->getName() << ": ";
	organisms.back()->draw();
	std::cout << std::endl;

	//pozycja antylop
	for (int i = 0; i < instancesNumber; i++)
	{
		int randomIndex = std::rand() % emptyFields.size();
		fieldIndex = emptyFields[randomIndex]->getPosY() * width + emptyFields[randomIndex]->getPosX();
		organisms.emplace_back(new Antelope(fields[fieldIndex], *this));
		fields[fieldIndex]->setOrganism(organisms.back());
		emptyFields.erase(emptyFields.begin() + randomIndex);
	}
	std::cout << organisms.back()->getName() << ": ";
	organisms.back()->draw();
	std::cout << std::endl;

	//pozycja trawy
	for (int i = 0; i < instancesNumber; i++)
	{
		int randomIndex = std::rand() % emptyFields.size();
		fieldIndex = emptyFields[randomIndex]->getPosY() * width + emptyFields[randomIndex]->getPosX();
		organisms.emplace_back(new Grass(fields[fieldIndex], *this));
		fields[fieldIndex]->setOrganism(organisms.back());
		emptyFields.erase(emptyFields.begin() + randomIndex);
	}
	std::cout << organisms.back()->getName() << ": ";
	organisms.back()->draw();
	std::cout << std::endl;

	//pozycja mleczy
	for (int i = 0; i < instancesNumber; i++)
	{
		int randomIndex = std::rand() % emptyFields.size();
		fieldIndex = emptyFields[randomIndex]->getPosY() * width + emptyFields[randomIndex]->getPosX();
		organisms.emplace_back(new Milt(fields[fieldIndex], *this));
		fields[fieldIndex]->setOrganism(organisms.back());
		emptyFields.erase(emptyFields.begin() + randomIndex);
	}
	std::cout << organisms.back()->getName() << ": ";
	organisms.back()->draw();
	std::cout << std::endl;

	//pozycja guarany
	for (int i = 0; i < instancesNumber; i++)
	{
		int randomIndex = std::rand() % emptyFields.size();
		fieldIndex = emptyFields[randomIndex]->getPosY() * width + emptyFields[randomIndex]->getPosX();
		organisms.emplace_back(new Guarana(fields[fieldIndex], *this));
		fields[fieldIndex]->setOrganism(organisms.back());
		emptyFields.erase(emptyFields.begin() + randomIndex);
	}
	std::cout << organisms.back()->getName() << ": ";
	organisms.back()->draw();
	std::cout << std::endl;


	//pozycja wilczych jagód
	for (int i = 0; i < instancesNumber; i++)
	{
		int randomIndex = std::rand() % emptyFields.size();
		fieldIndex = emptyFields[randomIndex]->getPosY() * width + emptyFields[randomIndex]->getPosX();
		organisms.emplace_back(new Belladonna(fields[fieldIndex], *this));
		fields[fieldIndex]->setOrganism(organisms.back());
		emptyFields.erase(emptyFields.begin() + randomIndex);
	}
	std::cout << organisms.back()->getName() << ": ";
	organisms.back()->draw();
	std::cout << std::endl;

	//pozycja barszczu sosnowskiego
	for (int i = 0; i < instancesNumber; i++)
	{
		int randomIndex = std::rand() % emptyFields.size();
		fieldIndex = emptyFields[randomIndex]->getPosY() * width + emptyFields[randomIndex]->getPosX();
		organisms.emplace_back(new SosnowskyHogweed(fields[fieldIndex], *this));
		fields[fieldIndex]->setOrganism(organisms.back());
		emptyFields.erase(emptyFields.begin() + randomIndex);
	}
	std::cout << organisms.back()->getName() << ": ";
	organisms.back()->draw();
	std::cout << std::endl;

	//usuñ elementy z wektora pustych pól
	for (int i = 0; i < emptyFields.size(); i++)
	{
		delete emptyFields.back();
		emptyFields.pop_back();
	}
}

World::~World()
{
	organisms.clear();
	organisms.shrink_to_fit();
	fields.clear();
	fields.shrink_to_fit();
}

void World::drawWorld() const
{
	std::cout << "\n Created by Michal Cellmer - 184685\n";
	std::cout << " ";
	for (int k = 0; k < 4*width-1; k++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cout << "|";
			if (fields[i * width + j]->isEmpty())
			{
				std::cout<<"   ";
			}
			else
			{
				std::cout << " ";
				fields[i * width + j]->getOrganism()->draw();
				std::cout << " ";
			}
		}
		std::cout << "|";
		std::cout << std::endl;
		std::cout << " ";
		for (int k = 0; k < 4 * width - 1; k++)
		{
			std::cout << "-";
		}
		std::cout << std::endl;
	}

}

void World::makeTurn(Direction direction)
{
	std::sort(organisms.begin(), organisms.end(), [](Organism* a, Organism* b) //posortuj organizmy po inicjatywie i wieku
		{
			if (a->getInitiative() == b->getInitiative())
				return a->getAge() > b->getAge();
			return a->getInitiative() > b->getInitiative();
		});

	for (int i=0;i<organisms.size();i++)
	{
		if (organisms[i]->isDead()) //pomiñ nie¿ywe organizmy
			continue;
		if (organisms[i]->getAge() < 0) //pomiñ nowonarodzone dzieci
		{
			organisms[i]->incrementAge();
			continue;
		}
		if (dynamic_cast<Human*>(organisms[i]))
		{
			organisms[i]->action(direction);
		}
		else
		{
			Direction randomDirection = organisms[i]->chooseDirection();
			organisms[i]->action(randomDirection);
		}

		organisms[i]->incrementAge();

	}
	eraseDead();
}

Field* World::findEmptyField(Field* field) const
{
	int fieldIndex = field->getPosY() * width + field->getPosX();
	if (field->getPosX() != 0)
	{
		if (fields[fieldIndex - 1]->isEmpty()) //pole na lewo
			return fields[fieldIndex - 1];
		if (field->getPosY() != 0 && fields[fieldIndex - width - 1]->isEmpty()) //górny lewy róg
			return fields[fieldIndex - width - 1];
		if (field->getPosY() != height-1 && fields[fieldIndex + width - 1]->isEmpty()) //dolny lewy róg
			return fields[fieldIndex + width - 1];
	}
	if (field->getPosX() != width - 1)
	{
		if (fields[fieldIndex + 1]->isEmpty()) //pole na prawo
			return fields[fieldIndex + 1]; 
		if (field->getPosY() != 0 && fields[fieldIndex - width + 1]->isEmpty()) //góny prawy róg
			return fields[fieldIndex - width + 1];
		if (field->getPosY() != height - 1 && fields[fieldIndex + width + 1]->isEmpty()) //dolny prawy róg
			return fields[fieldIndex + width + 1];
	}
	if (field->getPosY() != 0 && fields[fieldIndex - width]->isEmpty()) //pole w górê
		return fields[fieldIndex - width];
	if (field->getPosY() != height - 1 && fields[fieldIndex + width]->isEmpty()) //pole w dól
		return fields[fieldIndex + width];

	return nullptr; //nie znaleziono
}

void World::addOrganism(Organism* organism)
{
	organisms.push_back(organism);
}

void World::saveGameState(Human* player)
{
	std::ofstream fout("game_state.txt");
	fout << width << " " << height << std::endl;
	for (int i = 0; i < fields.size(); i++)
	{
		if (fields[i]->getOrganism())
			fout << fields[i]->getOrganism()->getName() << " " << fields[i]->getOrganism()->getStrength() << std::endl;
		else
			fout << "Empty\n";
	}
	fout << player->isImmortal() << " " << player->getCountImmortality();
	fout.close();
}

void World::loadGameState(Human** player)
{
	std::ifstream fin("game_state.txt");
	fin >> width;
	fin >> height;
	fields.clear();
	fields.shrink_to_fit();
	fields.reserve(width * height);
	for (int i = 0; i < height; i++) //ustaw wspó³rzêdne pól
	{
		for (int j = 0; j < width; j++)
		{
			fields.emplace_back(new Field(j, i));
		}
	}
	
	organisms.clear();
	organisms.shrink_to_fit();
	std::string name;
	int strength;
	for (int i = 0; i < width * height; i++)
	{
		fin >> name;
		if (name == "Empty")
			continue;
		else
		{
			if (name == "Human")
			{
				organisms.push_back(new Human(fields[i], *this));
				(*player) = dynamic_cast<Human*>(organisms.back());
			}

			else if (name == "Wolf")
				organisms.push_back(new Wolf(fields[i], *this));

			else if (name == "Sheep")
				organisms.push_back(new Sheep(fields[i], *this));

			else if (name == "Fox")
				organisms.push_back(new Fox(fields[i], *this));

			else if (name == "Turtle")
				organisms.push_back(new Turtle(fields[i], *this));

			else if (name == "Antelope")
				organisms.push_back(new Antelope(fields[i], *this));

			else if (name == "Grass")
				organisms.push_back(new Grass(fields[i], *this));

			else if (name == "Milt")
				organisms.push_back(new Milt(fields[i], *this));

			else if (name == "Guarana")
				organisms.push_back(new Guarana(fields[i], *this));

			else if (name == "Belladonna")
				organisms.push_back(new Belladonna(fields[i], *this));

			else if (name == "SosnowskyHogweed")
				organisms.push_back(new SosnowskyHogweed(fields[i], *this));

			fin >> strength;
			organisms.back()->increaseStrength(strength - organisms.back()->getStrength());
			fields[i]->setOrganism(organisms.back());
		}
	}
	bool immortality;
	fin >> immortality;
	if (immortality)
		(*player)->activateImmortality();
	int countImmortality;
	fin >> countImmortality;
	(*player)->setCountImmortality(countImmortality);
	fin.close();
}

void World::eraseDead()
{
	int orgNo = 0;
	for (int i = 0; i < organisms.size(); i++)
	{
		if (organisms[orgNo]->isDead())
		{
			organisms.erase(organisms.begin() + orgNo);
		}
		else
		{
			orgNo++;
		}
	}
}
