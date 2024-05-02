#include "playerFunctions.hpp"

struct Enemy {
    std::string name;
    int health;
    int attack;
};

Enemy createRandomEnemy();
void randomEvents(Player& player);
void mainBattle(Player& player, Enemy& enemy);
