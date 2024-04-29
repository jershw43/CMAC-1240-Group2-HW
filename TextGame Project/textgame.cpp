#include <iostream>
#include <string>
#include <ctime>
#include "playerFunctions.hpp"
#include "inventoryFunctions.hpp"
#include "player.hpp"
using namespace std;

/*
struct Player {
    string name;
    string className;
    int health;
    int attack;
    int defense;
    int level;
    int experience;
};
*/

/*
void setupPlayer(Player& player);
void printPlayer(Player player);
void levelUp(Player& player);
*/

void randomEvents(Player& player);
void mainBattle(Player& player);

int main() {

    srand(time(NULL));
    Player player;
    setupPlayer(player);

    while (player.health > 0) {
        randomEvents(player);
        printPlayer(player);

        if (player.health > 0) {
            mainBattle(player);
            printPlayer(player);
        }

        levelUp(player);
    }

    return 0;
}

/*
void setupPlayer(Player& player) {
    cout << "Welcome to the Text Game!\n" << endl;
    cout << "Please enter your name: ";
    cin >> player.name;
    cout << "Welcome, " << player.name << "!\n" << endl;
    cout << "Please choose a class: " << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Mage" << endl;
    cout << "3. Rogue" << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {
        player.health = 100;
        player.attack = 10;
        player.defense = 5;
        player.level = 1;
        player.experience = 0;
        player.className = "Warrior";
    }
    else if (choice == 2) {
        player.health = 80;
        player.attack = 15;
        player.defense = 3;
        player.level = 1;
        player.experience = 0;
        player.className = "Mage";
    }
    else if (choice == 3) {
        player.health = 90;
        player.attack = 12;
        player.defense = 4;
        player.level = 1;
        player.experience = 0;
        player.className = "Rogue";
    }
    else {
        cout << "Invalid choice. Please choose a valid class." << endl;
    }

    cout << "\nYou have chosen the " << player.className << " class.\n" << endl;
    cout << "You are level " << player.level << ", " << player.name << "." << endl;
    cout << "You have " << player.health << " health, " << player.attack << " attack, and " << player.defense << " defense." << endl;
    cout << "You have " << player.experience << " experience points.\n" << endl;

    cout << "You are now ready to begin your adventure!" << endl;
}

void printPlayer(Player player) {
    cout << "\nPlayer Information:" << endl;
    cout << "Name: " << player.name << endl;
    cout << "Class: " << player.className << endl;
    cout << "Health: " << player.health << endl;
    cout << "Attack: " << player.attack << endl;
    cout << "Defense: " << player.defense << endl;
    cout << "Level: " << player.level << endl;
    cout << "Experience: " << player.experience << "\n" << endl;
}

void levelUp(Player& player) {
    if (player.experience >= 100) {
        player.level++;
        player.experience -= 100;
        player.health += 10;
        player.attack += 5;
        player.defense += 2;
        cout << "You have leveled up!" << endl;
        cout << "You are now level " << player.level << "." << endl;
        cout << "You have " << player.health << " health, " << player.attack << " attack, and " << player.defense << " defense." << endl;
    }
}
*/

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
    cout << "You encountered a monster!" << endl;
    cout << "You have " << player.health << " health." << endl;
    cout << "The monster has 20 health." << endl;

    int monsterHealth = 20;

    while (player.health > 0 && monsterHealth > 0) {
        cout << "Choose an action: " << endl;
        cout << "1. Attack" << endl;
        cout << "2. Defend" << endl;
        cout << "3. Run" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "You attacked the monster!" << endl;
            monsterHealth -= player.attack;
            cout << "The monster has " << monsterHealth << " health." << endl;
        }
        else if (choice == 2) {
            cout << "You defended against the monster!" << endl;
            player.health -= 5;
            cout << "You have " << player.health << " health." << endl;
        }
        else if (choice == 3) {
            cout << "You ran away from the monster!" << endl;
            break;
        }

        if (monsterHealth > 0) {
            cout << "The monster attacked you!" << endl;
            player.health -= 5;
            cout << "You have " << player.health << " health." << endl;
        }
    }

    if (player.health <= 0) {
        cout << "You have been defeated!" << endl;
    }
    else {
        cout << "You have defeated the monster!" << endl;
        cout << "You gained 20 experience points." << endl;
        player.experience += 20;
    }
}
