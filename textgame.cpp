#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const int MAX_ENEMIES = 3;
const int MAX_ITEMS = 3;
const int MAX_PLAYERS = 3;

// Game complete bool
bool gameComplete = false;

// Parallel arrays to store player data
const char* playerNames[MAX_PLAYERS] = {"Warrior", "Mage", "Rogue"};
int playerHP[MAX_PLAYERS] = {20, 15, 10};
int playerDamage[MAX_PLAYERS] = {5, 3, 2};
int playerMP[MAX_PLAYERS] = {5, 10, 7};

// Parallel arrays to store enemy data
const char* enemyNames[MAX_ENEMIES] = {"Dragon", "Ogre", "Goblin"};
int enemyHP[MAX_ENEMIES] = {20, 15, 10};
int enemyDamage[MAX_ENEMIES] = {5, 3, 2};

// Parallel arrays to store item data
const char* itemNames[MAX_ITEMS] = {"Potion", "Sword", "Shield"};
const char* itemEffects[MAX_ITEMS] = {"restores 10 HP", "increases damage by 2", "increases defense"};

// Function to display player status
void displayPlayerStatus(int playerIndex) {
    cout << "Player: " << playerNames[playerIndex] << "\n";
    cout << "HP: " << playerHP[playerIndex] << "\n";
    cout << "MP: " << playerMP[playerIndex] << "\n";
}

// Function to simulate a battle encounter
void battleEncounter(int playerIndex) {
    int enemyIndex = rand() % MAX_ENEMIES; // Randomly select enemy

    // Sums all enemy hp together for completed game check
    int overallEnemyHP = 0;
    for (int x = 0; x < MAX_ENEMIES; x++) {
        overallEnemyHP += enemyHP[x];
    }

    // Checks if enemy has been defeated already
    if (enemyHP[enemyIndex] > 0) {
    
        cout << "You encounter a " << enemyNames[enemyIndex] << "!\n";

        // Simulate battle
        while (playerHP[playerIndex] > 0 && enemyHP[enemyIndex] > 0) {
            // Player's turn
            cout << "Your turn: Choose an action (1. Attack, 2. Use item, 3. Flee): ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                cout << "You attack the " << enemyNames[enemyIndex] << "!\n";
                enemyHP[enemyIndex] -= playerDamage[playerIndex];
                cout << "Enemy HP: " << enemyHP[enemyIndex] << "\n";
            }
            else if (choice == 2) {
                cout << "Choose an item to use:\n";
                for (int i = 0; i < MAX_ITEMS; ++i) {
                    cout << i+1 << ". " << itemNames[i] << " - " << itemEffects[i] << "\n";
                }
                int itemChoice;
                cin >> itemChoice;
                if (itemChoice >= 1 && itemChoice <= MAX_ITEMS) {
                    cout << "You use " << itemNames[itemChoice - 1] << "!\n";
                    if (itemChoice == 1){
                        playerHP[playerIndex] += 10; // Restore 10 HP
                        cout << "Your HP: " << playerHP[playerIndex] << "\n";
                    }
                    else if (itemChoice ==2) {
                        cout << "You use " << itemNames[itemChoice - 1] << "!\n";
                        // Apply sword item, increases player damage by 2 
                        playerDamage[playerIndex] += 2; // Increase Damage by 2
                        cout << "Your damage: " << playerDamage[playerIndex] << "\n"; 
                    }
                    else if  (itemChoice ==3) {    
                        cout << "You use " << itemNames[itemChoice - 1] << "!\n";
                        // Apply shield item, increasing damage is decreased by 1
                        enemyDamage[playerIndex] -= 1; // Decrease damage by 1
                        cout << "Enemy damage is now:  " << enemyDamage[enemyIndex] << "\n"; 
                    }
                }
                else{
                    cout << "Invalid item choice.\n";
                }
            }
            else if (choice == 3) {
                cout << "You flee from the battle!\n";
                break;
                cout << "Invalid choice. Try again.\n";
            }
            // Enemy's turn
            if (enemyHP[enemyIndex] > 0) {
                cout << "The " << enemyNames[enemyIndex] << " attacks you!\n";
                playerHP[playerIndex] -= enemyDamage[enemyIndex];
                cout << "Your HP: " << playerHP[playerIndex] << "\n";
            }
        }

        // Check battle outcome
        if (playerHP[playerIndex] <= 0) {
            cout << "Game over! You were defeated.\n";
        } else if (enemyHP[enemyIndex] <= 0) {
            cout << "You defeated the " << enemyNames[enemyIndex] << "!\n";
        }

        // Updates enemy hp sum
        for (int x = 0; x < MAX_ENEMIES; x++) {
            overallEnemyHP += enemyHP[x];
        }
    }
    // Checks if all enemies have been defeated using enemy hp sum
    else if (overallEnemyHP < 1) {
        cout << "All enemies have been defeated! Good job!" << endl;
        gameComplete = true;
    }
    // Rerandomizes enemy if selected enemy has been defeated already
    else {
        enemyIndex = rand() % MAX_ENEMIES;
    }
}

// Function for random events
void randomEvent(int playerIndex) {

    float randomEventNumber = rand() % 5 + 1;
    int randomEventDecision = 0;
    bool randomEventComplete = true;

    while (randomEventComplete) {

        if (randomEventNumber == 1) {
            cout << "You come across a statue in a decrepit ruin. Touching the cold stone fills you with vitality, reminding you of heroes of old. (+5 HP)" << endl;
            playerHP[playerIndex] += 5;
            randomEventComplete = false;
        }

        else if (randomEventNumber == 2) {
            cout << "While stumbling through a graveyard, an odd skeleton rises up from the ground. It offers you a smoothed stone before collapsing." << endl;
            randomEventComplete = false;
        }

        else if (randomEventNumber == 3) {
            cout << "You come across a vast pit, leaving you only one option. To jump over it." << endl << endl << "Press 1 to make the jump: ";
            cin >> randomEventDecision;
                if (randomEventDecision == 1) {
                    int pitFall = rand() % 1;
                    if (pitFall = 1) {
                        cout << "You cross the pit safely!" << endl;
                    }
                    else if (pitFall = 0) {
                        cout << "You stumble, falling into the pit! It takes hours to climb back out... (-10 HP)" << endl;
                        playerHP[playerIndex] - 10;
                    } 
                }
            randomEventComplete = false;

        }

        else if (randomEventNumber == 4) {
            cout << "You walk past a serene waterfall. You take a moment to sit down and catch your breath, it calms you." << endl;
            randomEventComplete = false;
        }

        else {
            cout << "You find a relaxing inn. You're offered a refreshing bowl of stew by the innkeep, an orc named Shimac. (+15 HP)" << endl;
            playerHP[playerIndex] += 15;
            randomEventComplete = false;
        }

    }

}

// Main function
int main() {
    // Seed random number generator
    srand(time(nullptr));

    // Character creation
    char playerName[50];
    cout << "Enter your name: ";
    cin >> playerName;

    cout << "Welcome, " << playerName << "! Choose your class (1. Warrior, 2. Mage, 3. Rogue): ";
    int playerClass;
    cin >> playerClass;

    int playerIndex = playerClass - 1;

    // Display player status
    displayPlayerStatus(playerIndex);

    // Start the game loop, random chance to pick random encounter or battle.
    while ((playerHP[playerIndex] > 0) && !gameComplete) {
        int adventureType = rand() % 2;

        if (adventureType == 1) {
            // Simulate random event
            randomEvent(playerIndex);
            adventureType++;
        }

        else {
        // Simulate battle encounter
        battleEncounter(playerIndex);
        }
    }

    return 0;
}