#include <iostream>
#include <conio.h>
#include "Organism.h"
#include "World.h"
#include "Direction.h"
#include "Human.h"
#include "Field.h"


int main()
{
    int width, height; //wymiary œwiata (w polach)
    std::cout << "Enter the width of the world: ";
    std::cin >> width;
    std::cout << "Enter the height of the world: ";
    std::cin >> height;
    Human* player = nullptr;
    World world(width, height, &player);
    Direction direction;
    char c;
    while (!player->isDead()) //g³ówna pêtla symulacji
    {
        world.drawWorld();

        std::cout << "\nMake your move (use arrow keys): \n";
        bool pressedGoodKey = false;
        while (!pressedGoodKey) //wykonuj a¿ u¿ytkownik wykona poprawny ruch
        {
            c = _getch();
            while ((int)c != 224 && (int)c != 0 && (int)c != -32)
            {
                if (c == 'q')
                {
                    if (!player->isImmortal() && player->getCountImmortality() == 0)
                    {
                        player->activateImmortality();
                        std::cout << "Immortality activated!" << std::endl;
                    }
                    else if(!player->isImmortal() && player->getCountImmortality()<10)
                        std::cout << " You can't activate immortality for the next " << 10 - player->getCountImmortality() << " rounds.\n";

                    else if (player->isImmortal())
                        std::cout << "Immortality has already been activated!\n";
                }
                else if (c == 's')
                {
                    std::cout << "Game saved!\n";
                    world.saveGameState(player);
                }
                else if (c == 'l')
                {
                    std::cout << "Game loaded!\n";
                    world.loadGameState(&player);
                    world.drawWorld();
                }
                else
                {
                    std::cout << "Wrong key!! Use arrow keys!\n";
                }
                c = _getch();
            }
            switch (c = _getch())
            {
            case 72: //góra
                if (player->getField()->getPosY() == 0)
                    std::cout << "You can't go up!" << std::endl;
                else
                {
                    direction = UP;
                    pressedGoodKey = true;
                }
                break;
            case 80: //dó³
                if (player->getField()->getPosY() == world.getHeight()-1)
                    std::cout << "You can't go down!" << std::endl;
                else
                {
                    direction = DOWN;
                    pressedGoodKey = true;
                }
                break;
            case 75: //lewo
                if (player->getField()->getPosX() == 0)
                    std::cout << "You can't go left!" << std::endl;
                else
                {
                    direction = LEFT;
                    pressedGoodKey = true;
                }
                break;
            case 77: //prawo
                if (player->getField()->getPosX() == world.getWidth()-1)
                    std::cout << "You can't go right!" << std::endl;
                else
                {
                    direction = RIGHT;
                    pressedGoodKey = true;
                }
                break;
            }
        }
          
        world.makeTurn(direction);

        if (player->isImmortal() || (player->getCountImmortality() < 10 && player->getCountImmortality() > 0))
        {
            player->setCountImmortality(player->getCountImmortality() + 1);
            if (player->getCountImmortality() == 5)
            {
                player->deactivateImmortality();
            }
            else if (player->getCountImmortality() == 10)
                player->setCountImmortality(0);
        }
    }

    std::cout << "YOU ARE DEAD!!!!" << std::endl;
}