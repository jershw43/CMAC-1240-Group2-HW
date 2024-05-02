#include <iostream>
#include <string>
#include <ctime>
#include<cstdlib>
#include "playerFunctions.hpp"
#include "inventoryFunctions.hpp"
#include "gameFunctions.hpp"
#include "player.hpp"
using namespace std;

int main(){


    srand(time(NULL));
    Player player;
    setupPlayer(player);

    string inventory[MAX_ITEMS];
    int inventorySize = 0;

    addItemToInventory("Potion", inventory, inventorySize);
    addItemToInventory("Sword", inventory, inventorySize);
    addItemToInventory("Shield", inventory, inventorySize);


    while (player.health > 0) {
        randomEvents(player);

        if (player.health > 0) {
            mainBattle(player,inventory,inventorySize);
        }

        levelUp(player);
    }

    return 0;
}

