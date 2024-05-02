#include "inventoryFunctions.hpp"
#include <iostream>
void addItemToInventory(string item, string inventory[], int& inventorySize){
	if (inventorySize < MAX_ITEMS){
		inventory[inventorySize++] = item;
		}
		else{
			cout <<"Inventory is full" << endl;
		}
	}

	
	
	void printInventory(string inventory[], int inventorySize){
		if (inventorySize == 0){
			cout << "Inventory is empty" << endl;
		}else {
			cout << "Inventory:" << endl;
			for (int i = 0; i < inventorySize; i++){
				cout << inventory[i] << endl;
			}
		}
	}
			
