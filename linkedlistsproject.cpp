#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

struct List {
    char name[20];
    int age;
    struct List *next;
};

struct List *insert(struct List *node, char *name, int age);
void printall(struct List *node);

int main() {
    struct List *head = 0;
    struct List *end = 0;
    
    int choice = 0;
    bool quit = false;
    bool delquit = false;
    do {
        printf("Select an option: (0) Quit, (1) Insert, (2) Print by Name, (3) Print by Age, (4) Deletion: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("You have selected Insert.\n");
                char buffer[20];
                int age = 0;

                printf("Input a name: ");
                scanf("%s", buffer);
                printf("Input an age: ");
                scanf("%d", &age);

                if (head == 0) {
                    head = insert(0, buffer, age);
                }
                else if (end == 0) {
                    end = insert(head, buffer, age);
                }
                else {
                    end = insert(end, buffer, age);
                }

                //printf("\nName: %s", buffer);
                //printf("\nAge: %d\n", age);
                break;
            }
            case 2: {
                printf("You have selected Print by Name.\n");

                if (head == 0) {
                    printf("No List Created.\n");
                }
                else {
                    printall(head);
                }

                break;
            }
            case 3: {
                printf("You have selected Print by Age.\n");
                //Insert print by age

                if (head == 0) {
                    printf("No List Created.\n");
                }
                else {
                    //Print ordered by age
                }

                break;
            }
            case 4: {
                printf("You have selected Deletion.\n");

                quit = true;
                break;
            }
            case 0: quit = true; delquit = true; break;
            default: printf("Invalid option. Please pick a valid option."); break;
        }
    } while (!quit);

    while (!delquit) {
        printf("Select an option: (0) Quit, (1) Delete a single entry, (2) Delete All: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("You have selected Delete a single entry.\n");
                //Insert delete single entry

                break;
            }
            case 2: {
                printf("You have selected Delete All.\n");
                //Insert delete all function

                break;
            }
            case 0: delquit = true; break;
            default: printf("Invalid option. Please pick a valid option."); break;
        }
    }

    return 0;
}

struct List *insert(struct List *node, char *name, int age) {

    struct List *newnode = (struct List *) malloc(sizeof(struct List));
    if (newnode == 0) {
        return 0;
    }

    strcpy(newnode->name, name);
    newnode->age = age;
    newnode->next = 0;

    if (node) {
        while (node->next) {
            node = node->next;
        }
        node->next = newnode;
    }

    return newnode;
}

void printall(struct List *node) {
    printf("List Ordered by Name:\n");
    while (node != 0) {
        printf("Name: %s\n", node->name);
        printf("Age: %d\n", node->age);
        node = node->next;
    }
}