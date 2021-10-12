#pragma once
#include <vector>
#include "Direction.h"
class Organism;
class Human;
class Field;

class World
{
public:
	World(int w, int h, Human** player); //konstruktor przyjmuj¹cy wymiary œwiata jako parametr
	~World();
	void drawWorld() const; //rysuje œwiat po ka¿dej turze
	void makeTurn(Direction direction); //wykonuje turê
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	std::vector<Organism*> getOrganisms() const { return organisms; }
	std::vector<Field*> getFields() const { return fields; }
	Field* findEmptyField(Field* field) const; //zwraca wska¿nik do pustego pola naoko³o pola przekazanego jako parametr
	void addOrganism(Organism* organism); //dodaje nowy organizm do wektora
	void saveGameState(Human* player); //zapisuje stan gry do pliku
	void loadGameState(Human** player); //wczytuje stan gry z pliku
private:
	int width;
	int height;
	std::vector<Organism*> organisms; //wszystkie organizmy w symulacji
	std::vector<Field*> fields; //wszystkie pola
	void eraseDead(); //usuwa z wektora wszystkie nie¿ywe organizmy
};

