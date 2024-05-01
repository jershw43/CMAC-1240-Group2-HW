#include "player.hpp"
#include "playerFunctions.hpp"
#include "gameFunctions.hpp"
#include <iostream>
#include <string>
using namespace std;

void randomEvents(Player& player) {
    int event = rand() % 3 + 1;

    if (event == 1) {
        cout << "\nYou found a chest!" << endl;
        cout << "You gained 10 experience points." << endl;
        player.experience += 10;
    }
    else if (event == 2) {
        cout << "\nYou encountered a monster!" << endl;
        cout << "You lost 10 health points." << endl;
        player.health -= 10;
    }
    else if (event == 3) {
        cout << "\nYou found a potion!" << endl;
        cout << "You gained 10 health points." << endl;
        player.health += 10;
    }
}

void mainBattle(Player& player) {
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
