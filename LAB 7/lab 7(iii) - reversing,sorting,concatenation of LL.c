#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void sortList(struct Node *head)
{
    struct Node *temp, *current;
    int swap;
    if (head == NULL)
        return;
    for (temp = head; temp->next != NULL; temp = temp->next)
    {
        for (current = temp->next; current != NULL; current = current->next)
        {
            if (temp->data > current->data)
            {
                swap = temp->data;
                temp->data = current->data;
                current->data = swap;
            }
        }
    }
}

struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int choice, val;

    while (1) {
        printf("\n--- LINKED LIST OPERATIONS ---\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display Both Lists\n");
        printf("4. Reverse List 1\n");
        printf("5. Sort List 1\n");
        printf("6. Concatenate List 2 into List 1\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value for List 1: ");
                scanf("%d", &val);
                list1 = insertEnd(list1, val);
                break;

            case 2:
                printf("Enter value for List 2: ");
                scanf("%d", &val);
                list2 = insertEnd(list2, val);
                break;

            case 3:
                printf("List 1: ");
                display(list1);
                printf("List 2: ");
                display(list2);
                break;

            case 4:
                list1 = reverseList(list1);
                printf("List 1 reversed: ");
                display(list1);
                break;

            case 5:
                sortList(list1);
                printf("List 1 sorted: ");
                display(list1);
                break;

            case 6:
                list1 = concatenate(list1, list2);
                list2 = NULL;
                printf("Concatenated List 1: ");
                display(list1);
                break;

            case 7:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
