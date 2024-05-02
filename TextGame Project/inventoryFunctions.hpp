#ifndef INVENTORYFUNCTIONS_HPP
#define INVENTORYFUNCTIONS_HPP

#include <string>
using namespace std; 

#define MAX_ITEMS 3

void addItemToInventory(string item, string inventory[], int& inventorySize);
void printInventory( string inventory[], int inventorySize);

#endif /*INVENTORYFUNCTIONS_HPP*/
