#include <iostream>
#include <string>
#include <ctime>
#include "playerFunctions.hpp"
#include "inventoryFunctions.hpp"
#include "gameFunctions.hpp"
#include "player.hpp"
using namespace std;

int main() {

    srand(time(NULL));
    Player player;
    setupPlayer(player);

    while (player.health > 0) {
        randomEvents(player);

        if (player.health > 0) {
        	Enemy enemy = createRandomEnemy();
            mainBattle(player, enemy);
        }

        levelUp(player);
    }

    return 0;
}
