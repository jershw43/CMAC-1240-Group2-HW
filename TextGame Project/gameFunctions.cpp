#include "player.hpp"
#include "playerFunctions.hpp"
#include "gameFunctions.hpp"
#include "inventoryFunctions.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

Enemy createRandomEnemy() {
	int randomNum = rand() % 3 + 1;
	
	if (randomNum == 1) {
		return {"Goblin", 10, 2};
	}
	else if (randomNum == 2) {
		return {"Ogre", 15, 3};
	}
	else if (randomNum == 3) {
		return {"Dragon", 20, 5};
	}
}

void randomEvents(Player& player) {
    int event = rand() % 3 + 1;

    if (event == 1) {
        cout << "\nYou found a chest!" << endl;
        cout << "You gained 10 experience points." << endl;
        player.experience += 10;
    }
    else if (event == 2) {
        cout << "\nYou step on a trap!" << endl;
        cout << "You lost 10 health points." << endl;
        player.health -= 10;
    }
    else if (event == 3) {
        cout << "\nYou found a potion!" << endl;
        cout << "You gained 10 health points." << endl;
        player.health += 10;
    }
}

void mainBattle(Player& player,string inventory[], int& inventorySize, Enemy& enemy) {
    cout << "\nYou encountered a " << enemy.name << "!" << endl;
    cout << "You have " << player.health << " health." << endl;
    cout << "The " << enemy.name << " has " << enemy.health << " health." << endl;

    while (player.health > 0 && enemy.health > 0) {
        cout << "Choose an action: " << endl;
        cout << "1. Attack" << endl;
        cout << "2. Defend" << endl;
        cout << "3. Run" << endl;
        cout << "4. Print Player Stats" << endl;
        cout << "5. Inventory" << endl;

        int choice;
        cin >> choice;
        bool fled = false;

        if (choice == 1) {
            cout << "\nYou attacked the " << enemy.name << "!" << endl;
            enemy.health -= player.attack;
            cout << "The " << enemy.name << " has " << enemy.health << " health." << endl;
        }
        else if (choice == 2) {
            cout << "\nYou defended against the " << enemy.name << "!" << endl;
            player.health -= (enemy.attack - player.defense);
            cout << "You have " << player.health << " health." << endl;
        }
        else if (choice == 3) {
            cout << "\nYou ran away from the " << enemy.name << "!" << endl;
            fled = true;
            break;
        }
        else if (choice == 4) {
            printPlayer(player);
            fled = true;
        }
        else if (choice == 5){
        	cout <<"\nInventory: " << endl;
			printInventory(inventory, inventorySize);
			cout << "Choose an item: " << endl;
			cout << "1. Potion - Restore 5HP" << endl;
			cout << "2. Sword -  Increase damage by 1" << endl;
			cout << "3. Shield - Increase defense by 1" << endl;
			
            int itemChoice,potiontracker,swordtracker,shieldtracker;
            cin >> itemChoice;

            if (itemChoice ==1){
                cout << "You use a potion. \nGain 5 health points. " << endl;
                player.health += 5;
                cout << "Current healthpoints: " << player.health << endl;            
            }
            else if (itemChoice ==2){
                cout << "You picked a secondary weapon. \nGain 1 attack points " << endl;
                player.attack += 1;
                cout << "Current attack value: " << player.attack << endl;
            }
            else if (itemChoice ==3){
                cout << "You picked a shield. \nGain 1 defense points " << endl;
                player.defense += 1;
                cout << "Current defense value: " << player.defense << endl;
            }
            
			fled = true;
		}
		

        if (enemy.health > 0 && !fled) {
            cout << "The " << enemy.name << " attacked you!" << endl;
            player.health -= enemy.attack;
            cout << "You have " << player.health << " health." << endl;
        }
    }

    if (player.health <= 0) {
        cout << "You have been defeated!" << endl;
    }
    else if (enemy.health <= 0) {
        cout << "You have defeated the " << enemy.name << "!" << endl;
        cout << "You gained 20 experience points." << endl;
        player.experience += 20;
    }
}

