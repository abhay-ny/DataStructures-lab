#include <stdio.h>
#include <stdlib.h> // Include for malloc() and exit()

struct Node {
    int data;
    struct Node *link;
};

typedef struct Node node;
node *start = NULL;

void insertAtBeginning() {
    node *new1 = (node*)malloc(sizeof(node)); // Allocate memory for new node
    if (new1 == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    printf("Enter value to insert at beginning: ");
    scanf("%d", &new1->data);
    
    new1->link = start;  // New node points to the current start
    start = new1;        // Update start to point to the new node
}

void insertAtEnd() {
    node *new1 = (node*)malloc(sizeof(node)); // Allocate memory for new node
    if (new1 == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    printf("Enter value to insert at end: ");
    scanf("%d", &new1->data);
    
    new1->link = NULL;  // New node will be the last node, so its link is NULL
    
    if (start == NULL) {
        start = new1;  // If list is empty, new node becomes the first node
    } else {
        node *temp = start;
        while (temp->link != NULL) { // Traverse to the last node
            temp = temp->link;
        }
        temp->link = new1;  // Last node's link points to new node
    }
}

void insertAtPosition() {
    int pos;
    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    // Validate position
    if (pos < 1) {
        printf("Invalid position. Position should be >= 1.\n");
        return;
    }
    
    node *new1 = (node*)malloc(sizeof(node)); // Allocate memory for new node
    if (new1 == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    printf("Enter value to insert at position %d: ", pos);
    scanf("%d", &new1->data);
    
    if (pos == 1) {
        // If inserting at the first position, it's similar to insert at beginning
        new1->link = start;
        start = new1;
    } else {
        node *temp = start;
        for (int i = 1; i < pos - 1; i++) {
            if (temp == NULL) {
                printf("Position out of range.\n");
                free(new1);  // Free the allocated memory if the position is invalid
                return;
            }
            temp = temp->link; // Traverse to the node before the position
        }

        // Now, temp points to the node before the insertion point
        new1->link = temp->link; // Link the new node to the next node
        temp->link = new1; // Update the previous node's link to the new node
    }
}

void deleteAtBeginning() {
    if (start == NULL) {
        printf("The list is empty, nothing to delete.\n");
        return;
    }
    
    node *temp = start;    // Temporary pointer to hold the start node
    start = start->link;   // Move start to the next node
    free(temp);            // Free the memory of the old start node
    
    printf("Node deleted from the beginning.\n");
}

void deleteAtEnd() {
    if (start == NULL) {
        printf("The list is empty, nothing to delete.\n");
        return;
    }
    
    if (start->link == NULL) {
        // Only one node in the list
        free(start);
        start = NULL;
        printf("Node deleted from the end.\n");
        return;
    }
    
    node *temp = start;
    while (temp->link != NULL && temp->link->link != NULL) { // Traverse to the second last node
        temp = temp->link;
    }
    
    free(temp->link);  // Free memory of the last node
    temp->link = NULL; // Update second last node's link to NULL
    
    printf("Node deleted from the end.\n");
}

void deleteAtPosition() {
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    // Validate position
    if (pos < 1 || start == NULL) {
        printf("Invalid position or list is empty.\n");
        return;
    }
    
    if (pos == 1) {
        // If deleting the first node
        node *temp = start;
        start = start->link;
        free(temp);
        printf("Node deleted from position 1.\n");
        return;
    }

    node *temp = start;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL || temp->link == NULL) {
            printf("Position out of range.\n");
            return;
        }
        temp = temp->link;
    }

    node *delNode = temp->link;  // Node to be deleted
    temp->link = temp->link->link;  // Skip the node to be deleted
    free(delNode);  // Free the memory of the deleted node
    
    printf("Node deleted from position %d.\n", pos);
}

void display() {
    node *temp;
    if (start == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    
    printf("Elements in the linked list: ");
    temp = start;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    int ch;
    
    while (1) {
        printf("1: Insert at Beginning  2: Insert at End  3: Insert at Position  4: Delete at Beginning  5: Delete at End  6: Delete at Position  7: Display  8: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insertAtBeginning();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                insertAtPosition();
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                deleteAtPosition();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);  // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
