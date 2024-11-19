#include <stdio.h>
#include <stdlib.h>

// Definition of a Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the linked list          
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
void reverse(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to sort the linked list
void sort(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) return;

    struct Node *i, *j;
    int temp;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Function to concatenate two linked lists
void concatenate(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }
    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = *head2;
}

// Menu-driven program
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    int choice, value;
    do {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Append to List 1\n");
        printf("2. Append to List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Reverse List 1\n");
        printf("6. Sort List 1\n");
        printf("7. Concatenate List 2 into List 1\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to append to List 1: ");
                scanf("%d", &value);
                append(&list1, value);
                break;
            case 2:
                printf("Enter value to append to List 2: ");
                scanf("%d", &value);
                append(&list2, value);
                break;
            case 3:
                printf("List 1: ");
                display(list1);
                break;
            case 4:
                printf("List 2: ");
                display(list2);
                break;
            case 5:
                reverse(&list1);
                printf("List 1 reversed.\n");
                break;
            case 6:
                sort(&list1);
                printf("List 1 sorted.\n");
                break;
            case 7:
                concatenate(&list1, &list2);
                printf("List 2 concatenated into List 1.\n");
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 8);

    return 0;
}
