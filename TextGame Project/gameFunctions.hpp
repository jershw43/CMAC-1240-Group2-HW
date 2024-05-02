#include "playerFunctions.hpp"
#include "inventoryFunctions.hpp"

struct Enemy {
	std::string name;
	int health;
	int attack;
};

Enemy createRandomEnemy();
void randomEvents(Player& player);
void mainBattle(Player& player,string inventory[],int& inventorySize, Enemy& enemy);
