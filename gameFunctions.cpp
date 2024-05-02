#include "player.hpp"
#include "playerFunctions.hpp"
#include "gameFunctions.hpp"
#include "inventoryFunctions.hpp"
#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;

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

void mainBattle(Player& player,string inventory[], int& inventorySize) {
    cout << "\nYou encountered a monster!" << endl;
    cout << "You have " << player.health << " health." << endl;
    cout << "The monster has 20 health." << endl;

    int monsterHealth = 20;

    while (player.health > 0 && monsterHealth > 0) {
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
            cout << "\nYou attacked the monster!" << endl;
            monsterHealth -= player.attack;
            cout << "The monster has " << monsterHealth << " health." << endl;
        }
        else if (choice == 2) {
            cout << "\nYou defended against the monster!" << endl;
            player.health -= 5;
            cout << "You have " << player.health << " health." << endl;
        }
        else if (choice == 3) {
            cout << "\nYou ran away from the monster!" << endl;
            fled = true;
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
		

        if (monsterHealth > 0 && !fled) {
            cout << "The monster attacked you!" << endl;
            player.health -= 5;
            cout << "You have " << player.health << " health." << endl;
        }
    }

    if (player.health <= 0) {
        cout << "You have been defeated!" << endl;
    }
    else if (monsterHealth <= 0) {
        cout << "You have defeated the monster!" << endl;
        cout << "You gained 20 experience points." << endl;
        player.experience += 20;
    }
}

