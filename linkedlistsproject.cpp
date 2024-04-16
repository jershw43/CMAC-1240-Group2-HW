//Mike-Revision/Deletion
//Tanner-Menu/Insertion/Sorting

#include <cstdlib>
#include <cstdio>
#include <cstring>

struct List {
    char firstName[20];
    char lastName[20];
    int age;
    struct List *next;
};

// Insert data
struct List *insert(struct List *node, char *firstName, char *lastName, int age);
// Swaps pointers - used for the bubblesort
struct List *swap(struct List *ptr1, struct List *ptr2);
// Counts the amount of structs created - used for bubblesort
int count(struct List *node);
// Bubblesort based on last name
void bubbleSort_lastName(struct List **head, int count);
// Bubblesort based on age
void bubbleSort_age(struct List **head, int count);
// Delete single entry by last name
int deleteNode_lastName(struct List **head, char *lastName);
// Delete single entry by age
int deleteNode_age(struct List **head, int search);
// Delete all
void del_list(struct List *head);
// Prints the list
void printList(struct List *node);

int main() {
    struct List *head = 0;
    struct List *end = 0;
    
    int choice = 0;
    bool quit = false;
    do {
        printf("Select an option: (0) Quit, (1) Insert, (2) Print by Last Name, (3) Print by Age, (4) Delete by Last Name, (5) Delete by Age, (6) Delete All: ");
        fflush(stdout);
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char bufferFirst[50];
                char bufferLast[50];
                int age = 0;

                // Ask user to input first name
                printf("Input first name: ");
                fflush(stdout);
                scanf("%49s", bufferFirst);

                // Ask user to input last name
                printf("Input last name: "); 
                fflush(stdout);
                scanf("%49s", bufferLast);

                // Ask user to input age
                printf("Input an age: "); 
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
            case 3: {
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
            case 4: {
                printf("You have selected Delete Entry by Last Name.\n");

                if (head == 0) {
                    printf("No List Created.\n");
                }
                else {
                    char lastName[20];
                    printf("Enter the last name to delete: ");
                    fflush(stdout);
                    scanf("%s", lastName);

                    if (deleteNode_lastName(&head, lastName)) {
                        printf("Sucessfully deleted entry.\n");
                    } else {
                        printf("Failed to delete specified entry.\n");
                    }
                }
                break;
            }
            case 5: {
                printf("You have selected Delete Entry by Age.\n");
                int input = 0;

                if (head == 0) {
                    printf("No List Created.\n");
                }
                else {
                    printf("Enter the age to delete: ");
                    fflush(stdout);
                    scanf("%d", &input);
                    if (deleteNode_age(&head, input)) {
                        printf("Sucessfully deleted entry.\n");
                    }
                    else {
                        printf("Failed to delete specified entry.\n");
                    }
                }

                break;
            }
            case 6: {
                printf("You have selected Delete All Entries.\n");

                if (head == 0) {
                    printf("No List Created.\n");
                }
                else {
                    del_list(head);
                    if(head == NULL)
                        printf("List deleted successfully\n");
                }

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
    struct List *temp = node;
    while (temp != 0) {
        printf("Name: %s, %s\n", temp->lastName, temp->firstName);
        printf("Age: %d\n", temp->age);
        temp = temp->next;
    }
}

void del_list(struct List *head) {
	struct List *temp = head;
    struct List *next;
	
	while(temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}

    head = NULL;
}

int deleteNode_lastName(struct List **head, char *lastName) {
    // function to search for input char and delete associated entry, returning 1 for successful deletion and 0 for failure
    if (*head && strcmp((*head)->lastName, lastName) == 0) {
        struct List *temp = (*head)->next;
        free(*head);
        *head = temp;
        return 1;
    }

    struct List *prev = *head;
    struct List *current = (*head)->next;

    while (current) {
        if (strcmp(current->lastName, lastName) == 0) {
            prev->next = current->next;
            free(current);
            return 1;
        }
    }

    return 0;
}

int deleteNode_age(struct List ** head, int search) {
	//deal with first node in list
	if (head && (*head)) {
		if ((*head)->age == search) {
			//we've found the item in the head of the list
			struct List * temp = (*head)->next;
			free(*head);
			*head = temp;
			return 1; //we found the node to delete.
		}
		//else, we check the other items
		struct List * node = (*head);
		while (node->next) {
			if (node->next->age == search) {
				//delete this node, move the pointer, etc. head contains prev head.
				struct List * temp = node->next->next; //get the node after the node we are deleting.
				free(node->next); //free the node we are looking at
				node->next = temp; //reroute node's next to one after
				//notice that head is not changed here.
				return 1;
			}
			//we didn't find the data at this node, so continue...
			node = node->next; //go to next node in list
		}
	}
	return 0;
}
