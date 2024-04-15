#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

struct List {
    char firstName[20];
    char lastName[20];
    int age;
    struct List *next;
};

struct List *insert(struct List *node, char *firstName, char *lastName, int age);

struct List* del_list(struct List *head)
{
	struct List *temp = head;
	
	while(temp != NULL)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
	return head;
}

struct List *swap(struct List *ptr1, struct List *ptr2);
void bubbleSort_lastName(struct List **head, int count);
void bubbleSort_age(struct List **head, int count);
int count(struct List *node);
void printList(struct List *node);

// Submenus - Load functions for submenus above these
void printMenu(struct List *head);
void deletionMenu(struct List *head);

int main() {
    struct List *head = 0;
    struct List *end = 0;
    
    int choice = 0;
    bool quit = false;
    do {
        printf("Select an option: (0) Quit, (1) Insert, (2) Print Menu, (3) Deletion Menu: ");
        fflush(stdout);
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char bufferFirst[50];
                char bufferLast[50];
                int age = 0;

                printf("Input first name: "); // Ask user to input first name
                fflush(stdout);
                scanf("%49s", bufferFirst);
                printf("Input last name: "); // Ask user to input last name
                fflush(stdout);
                scanf("%49s", bufferLast);
                printf("Input an age: "); // Ask user to input age
                fflush(stdout);
                scanf("%d", &age);

                // Creates the linked list
                if (head == 0) {
                    head = insert(0, bufferFirst, bufferLast, age);
                }
                else if (end == 0) {
                    end = insert(head, bufferFirst, bufferLast, age);
                }
                else {
                    end = insert(end, bufferFirst, bufferLast, age);
                }

                break;
            }
            case 2: {
                printMenu(head); // Switches to the print menu
                break;
            }
            case 3: {
                deletionMenu(head); // Switches to the deletion menu
                break;
            }
            case 0: quit = true; break;
            default: printf("Invalid option. Please pick a valid option."); break;
        }
    } while (!quit);

    return 0;
}

struct List *insert(struct List *node, char *firstName, char *lastName, int age) {
    struct List *newnode = (struct List *) malloc(sizeof(struct List));
    if (newnode == 0) {
        return 0;
    }

    strcpy(newnode->firstName, firstName);
    strcpy(newnode->lastName, lastName);
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

struct List *swap(struct List *ptr1, struct List *ptr2) {
    struct List *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

void bubbleSort_lastName(struct List **head, int count) {
    struct List **h;
    int i, j, swapped;

    for (i = 0; i <= count; i++) {
        h = head;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++) {
            struct List *p1 = *h;
            struct List *p2 = p1->next;

            if (strcmp(p1->lastName, p2->lastName) > 0) {
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }

        if (swapped == 0) {
            break;
        }
    }
}

void bubbleSort_age(struct List **head, int count) {
    struct List **h;
    int i, j, swapped;

    for (i = 0; i <= count; i++) {
        h = head;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++) {
            struct List *p1 = *h;
            struct List *p2 = p1->next;

            if (p1->age > p2->age) {
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }

        if (swapped == 0) {
            break;
        }
    }
}

int count(struct List *node) {
    struct List *current = node;
    int count = 0;
    while (current != 0) {
        count++;
        current = current->next;
    }
    return count;
}

void printList(struct List *node) {
    while (node != 0) {
        printf("Name: %s, %s\n", node->lastName, node->firstName);
        printf("Age: %d\n", node->age);
        node = node->next;
    }
}

void printMenu(struct List *head) {
    int choice = 0;
    bool quit = false;

    do {
        printf("Select Print option: (0) Go back, (1) Print by Last Name, (2) Print by Age: ");
        fflush(stdout);
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                if (head == 0) {
                    printf("No List Created.\n");
                }
                else {
                    printf("List Ordered by Last Name:\n");
                    bubbleSort_lastName(&head, count(head));
                    printList(head);
                }

                break;
            }
            case 2: {
                if (head == 0) {
                    printf("No List Created.\n");
                }
                else {
                    printf("List Ordered by Age:\n");
                    bubbleSort_age(&head, count(head));
                    printList(head);
                }

                break;
            }
            case 0: quit = true; break;
            default: printf("Invalid option. Please pick a valid option."); break;
        }
    } while (!quit);
}

void deletionMenu(struct List *head) {
    int choice = 0;
    bool quit = false;

    do {
        printf("Select Deletion option: (0) Go back, (1) Delete Single Entry, (2) Delete All Entries: ");
        fflush(stdout);
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("You have selected Delete Single Entry.\n");

                if (head == 0) {
                    printf("No List Created.\n");
                }
                else {
                    // Insert delete single entry here
                }

                break;
            }
            case 2: {
                printf("You have selected Delete All Entries.\n");

                if (head == 0) {
                    printf("No List Created.\n");
                }
                else {
                    head = del_list(head);
                	if(head == NULL)
                		printf("List deleted successfully");
                }

                break;
            }
            case 0: quit = true; break;
            default: printf("Invalid option. Please pick a valid option."); break;
        }
    } while (!quit);
}
