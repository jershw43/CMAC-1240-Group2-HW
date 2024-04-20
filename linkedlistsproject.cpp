//Mike-Revision/Deletion
//Tanner-Menu/Insertion/Sorting
//Taryn-Deletion/Debugging
//Josh-Debugging/Revision

#include <cstdlib>
#include <cstdio>
#include <cstring>

struct List {
    char name[20];
    int age;
    struct List *next;
};

// Insert data
struct List *insert(struct List *node, char *name, int age);
// Swaps pointers - used for the bubblesort
struct List *swap(struct List *ptr1, struct List *ptr2);
// Counts the amount of structs created - used for bubblesort
int count(struct List *node);
// Bubblesort based on name
void bubbleSort_name(struct List **head, int count);
// Bubblesort based on age
void bubbleSort_age(struct List **head, int count);
// Delete single entry by name
int deleteNode_name(struct List **head, char *name);
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
        printf("Select an option:\n(0) Quit\n(1) Insert\n(2) Print by Last Name\n(3) Print by Age\n(4) Delete by Last Name\n(5) Delete by Age\n(6) Delete All:\n");
        fflush(stdout);
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char buffer[50];
                int age = 0;

                // Ask user to input name
                printf("Input first name: ");
                fflush(stdout);
                scanf("%49s", buffer);

                // Ask user to input age
                printf("Input an age: "); 
                fflush(stdout);
                scanf("%d", &age);

                // Creates the linked list
                if (head == 0) {
                    head = insert(0, buffer, age);
                }
                else if (end == 0) {
                    end = insert(head, buffer, age);
                }
                else {
                    end = insert(end, buffer, age);
                }
                break;
            }
            case 2: {
                if (head == 0) {
                    printf("No List Created.\n");
                }
                else {
                    printf("List Ordered by Name:\n");
                    bubbleSort_name(&head, count(head));
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
                printf("You have selected Delete Entry by Name.\n");

                if (head == 0) {
                    printf("No List Created.\n");
                }
                else {
                    char lastName[20];
                    printf("Enter the name to delete: ");
                    fflush(stdout);
                    scanf("%s", lastName);

                    if (deleteNode_name(&head, lastName)) {
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
                    head = 0;
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

            if (strcmp(p1->name, p2->name) > 0) {
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
        printf("Name: %s\n", temp->name);
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

int deleteNode_name(struct List **head, char *name) {
    // function to search for input char and delete associated entry, returning 1 for successful deletion and 0 for failure
    if (*head && strcmp((*head)->name, name) == 0) {
        struct List *temp = (*head)->next;
        free(*head);
        *head = temp;
        return 1;
    }

    struct List *prev = *head;
    struct List *current = (*head)->next;

    while (current) {
        if (strcmp(current->name, name) == 0) {
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
