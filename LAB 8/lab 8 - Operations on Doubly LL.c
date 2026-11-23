#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void createList(struct Node **head) {
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &val);

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory Allocation failed\n");
            return;
        }
        newNode->data = val;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
        } else {
            struct Node *temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}
void insertLeft(struct Node **head, int target, int newVal) {
    struct Node *temp = *head;

    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory Allocation failed\n");
        return;
    }

    newNode->data = newVal;
    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        *head = newNode;
    }
    temp->prev = newNode;
}
void deleteNode(struct Node **head, int val) {
    if (*head == NULL) {
        printf("Empty\n");
        return;
    }

    struct Node *temp = *head;
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if (temp->prev == NULL) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        printf("%d deleted\n", temp->data);
        free(temp);
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        printf("%d deleted\n", temp->data);
        free(temp);
    }
}

void display(struct Node **head) {
    struct Node *temp = *head;
    if (*head == NULL) {
        printf("Empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 4) Display reverse
void displayReverse(struct Node **head) {
    struct Node *temp = *head;
    if (*head == NULL) {
        printf("Empty\n");
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int choice, target, val;

    while (1) {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Insert to the left of a value\n");
        printf("3. Delete node by value\n");
        printf("4. Display (Forward)\n");
        printf("5. Display (Reverse)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList(&head);
                break;
            case 2:
                printf("Enter the target value to insert before: ");
                scanf("%d", &target);
                printf("Enter the new value to insert: ");
                scanf("%d", &val);
                insertLeft(&head, target, val);
                break;
            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &val);
                deleteNode(&head, val);
                break;
            case 4:
                display(&head);
                break;
            case 5:
                displayReverse(&head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
