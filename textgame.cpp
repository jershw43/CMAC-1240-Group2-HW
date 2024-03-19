//Tanner Lauritzen - enemy defeated checks, debugging
//Taryn Dillie - added level system, debugging
//Josh Watson - debugging, magic system, item system
//Michael Wilson - debugging, game documentation

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const int MAX_ENEMIES = 3;
const int MAX_ITEMS = 3;
const int MAX_PLAYERS = 3;
const int MAX_LEVELS = 3;

// For alternating events
int adventureType = 0;

// Game complete bool
bool gameComplete = false;

// Keeps track of enemies defeated
int enemyDefeatedCount = 0;

//Keeps track of player level
int playerLevel = 0;

// Parallel arrays to store player data
const char* playerNames[MAX_PLAYERS] = {"Warrior", "Mage", "Rogue"};
int playerHP[MAX_PLAYERS] = {20, 15, 10};
int playerDamage[MAX_PLAYERS] = {5, 3, 2};
int playerMP[MAX_PLAYERS] = {5, 10, 7};

// Parallel arrays to store enemy data
const char* enemyNames[MAX_ENEMIES] = {"Dragon", "Ogre", "Goblin"};
int enemyHP[MAX_ENEMIES] = {20, 15, 10};
int enemyDamage[MAX_ENEMIES] = {5, 3, 2};
bool enemyDefeated[MAX_ENEMIES] = {false, false, false};

// Parallel arrays to store item data
const char* itemNames[MAX_ITEMS] = {"Potion", "Sword", "Shield"};
const char* itemEffects[MAX_ITEMS] = {"restores 10 HP", "increases damage by 2", "increases defense by 1"};


//Parallel arrays to store player level data
const char* levelNames[MAX_LEVELS] = {"Level 1", "Level 2", "Level 3"};
const char* levelEffects[MAX_LEVELS] = {"increases to 20 HP", "increases to 40 HP", "increases to 60 HP"};

// Function to display player status
void displayPlayerStatus(int playerIndex) {
    cout << "Player: " << playerNames[playerIndex] << "\n";
    cout << "HP: " << playerHP[playerIndex] << "\n";
    cout << "MP: " << playerMP[playerIndex] << "\n";
}

//Function to display player level
void displayPlayerLevel(int playerLevel, int playerIndex){
	switch (playerLevel)
	{
	case 0: {playerHP[playerIndex] += 20;
		cout << "You are now " << levelNames[0] << "!\n";
		cout << "Your health " << levelEffects[0] << "!\n";
		break;
	}
	case 1:{playerHP[playerIndex] += 40;
		cout << "You are now " << levelNames[1] << "!\n";
		cout << "Your health " << levelEffects[1] << "!\n";
		break;
	}
	case 2:{playerHP[playerIndex] += 60;
		cout << "You are now " << levelNames[2] << "!\n";
		cout << "Your health " << levelEffects[2] << "!\n";
		break;
		}
	}
}

// Function for random events
void randomEvent(int playerIndex) {

    int randomEventNumber = rand() % 5;
    int randomEventDecision = 0;
    bool randomEventComplete = true;

    while (randomEventComplete) {

        if (randomEventNumber == 1) {
            cout << "You come across a statue in a decrepit ruin. Touching the cold stone fills you with vitality, reminding you of heroes of old. (+5 HP)" << endl;
            playerHP[playerIndex] += 5;
            randomEventComplete = false;
            break;
        }

        else if (randomEventNumber == 2) {
            cout << "While stumbling through a graveyard, an odd skeleton rises up from the ground. It offers you a smoothed stone before collapsing." << endl;
            randomEventComplete = false;
            break;
        }

        else if (randomEventNumber == 3) {
            cout << "You come across a vast pit, leaving you only one option. To jump over it." << endl << endl << "Press 1 to make the jump: ";
            cin >> randomEventDecision;
                if (randomEventDecision == 1) {
                    int pitFall = rand() % 2;
                    if (pitFall == 1) {
                        cout << "You cross the pit safely!" << endl;
                    }
                    else if (pitFall == 0) {
                        cout << "You stumble, falling into the pit! It takes hours to climb back out... (-10 HP)" << endl;
                        playerHP[playerIndex] -= 10;
                    } 
                }
            randomEventComplete = false;
            break;

        }

        else if (randomEventNumber == 4) {
            cout << "You walk past a serene waterfall. You take a moment to sit down and catch your breath, it calms you." << endl;
            randomEventComplete = false;
            break;
        }

        else {
            cout << "You find a relaxing inn. You're offered a refreshing bowl of stew by the innkeep, an orc named Shimac. (+15 HP)" << endl;
            playerHP[playerIndex] += 15;
            randomEventComplete = false;
            break;
        }

    }

}

// Function to simulate a battle encounter
void battleEncounter(int playerIndex) {
    int enemyIndex = rand() % MAX_ENEMIES; // Randomly select enemy

    // Checks if enemy has been defeated already
    if (!enemyDefeated[enemyIndex]) {
    
        cout << "You encounter a " << enemyNames[enemyIndex] << "!\n";

        // Simulate battle
        while (playerHP[playerIndex] > 0 && enemyHP[enemyIndex] > 0) {
            // Player's turn
            cout << "Your turn: Choose an action (1. Attack, 2. Use item, 3. Magic 4. Flee): ";
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
                    
                    if (itemChoice == 1 ){
                        playerHP[playerIndex] += 10; // Restore 10 HP
                        cout << "Your HP: " << playerHP[playerIndex] << "\n";
                        
                    }
                    else if (itemChoice ==2 ) {
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
            else if (choice == 3)
            {
                cout << "Choose your magic: 1. Fire, 2. Lightning, 3. Ice, 4. Flee: ";
                    int choice;
                    cin >> choice;
                    if (choice == 1)
                    {
                        cout << "You chose fire: " << endl;
                        if (strcmp(enemyNames[enemyIndex], "Dragon") == 0 )
                        {
                            cout << "With fire running through the veins of the Dragon, your fire spell is less effective. " << "\n";
                            playerDamage[playerIndex] -=1;
                            cout << "Your damage: " << playerDamage[playerIndex] << "\n";
                        }
                        else 
                        {
                            playerDamage[playerIndex] = 4;
                            cout << "Your damage: " << playerDamage[playerIndex] << "\n";
                        }
                    }
                else if (choice == 2)
                    {
                        cout << "You chose lightning: " << endl;
                        if (strcmp(enemyNames[enemyIndex], "Goblin") == 0 )
                        {
                            cout << "The Goblin has taken a liking to rubber boots it got from a previous victim. Your lightning spell is less effective." << "\n";
                            playerDamage[playerIndex] -=1;
                            cout << "Your damage: " << playerDamage[playerIndex] << "\n";
                        }
                        else 
                        {
                            playerDamage[playerIndex] = 4;
                            cout << "Your damage: " << playerDamage[playerIndex] << "\n";
                        }
                    }
                else if (choice == 3)
                    {
                        cout << "You chose ice: " << endl;
                        if (strcmp(enemyNames[enemyIndex], "Ogre") == 0 )
                        {
                            cout << "The Ogre has a thick hide that will be tough to break. Your ice spell is less effective." << "\n";
                            playerDamage[playerIndex] -=1;
                            cout << "Your damage: " << playerDamage[playerIndex] << "\n";
                        }
                        else 
                        {
                            playerDamage[playerIndex] = 4;
                            cout << "Your damage: " << playerDamage[playerIndex] << "\n";
                        }
                    }
                else if (choice == 4)
                {
                    break;
                }   
            }
            else if (choice == 4) {
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
            enemyDefeated[enemyIndex] = true;
            enemyDefeatedCount++;
            displayPlayerLevel(playerLevel, playerIndex);
            playerLevel++;
        }

	// Simulate a random event
	int adventureTypeResultant = rand() % 2;
	if (adventureTypeResultant == 1) {
            randomEvent(playerIndex); 
        }
    }
    // Checks if all enemies have been defeated
    else if (enemyDefeatedCount == MAX_ENEMIES) {
        cout << "All enemies have been defeated! Good job!" << endl;
        gameComplete = true;
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

    cout << "Welcome, " << playerName << "! Defeat all 3 enemies to succed on your quest, but if you run out of HP then you have failed on your quest!\n Choose your class (1. Warrior, 2. Mage, 3. Rogue): ";
    int playerClass;
    cin >> playerClass;

    int playerIndex = playerClass - 1;

    // Display player status
    displayPlayerStatus(playerIndex);

        // Start the game loop, random chance to pick random encounter or battle.
    while ((playerHP[playerIndex] > 0) && !gameComplete) {
    int adventureTypeResultant = adventureType % 2;

        adventureType++;

        if (adventureTypeResultant == 1) {
            // Simulate random event
            randomEvent(playerIndex);
            
        }

        else {
            // Simulate battle encounter
            battleEncounter(playerIndex);
        
        }
    }
    return 0;
}
