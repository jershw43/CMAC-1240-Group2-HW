#include "playerFunctions.hpp"
#include "player.hpp"
#include <iostream>
#include <string>
using namespace std;

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