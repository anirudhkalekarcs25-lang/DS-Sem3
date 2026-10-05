#include <stdio.h>
#define MAX 3
int queue[MAX];
int front = -1, rear = -1;
void insert(int num) {
    if (rear == MAX - 1) {
        printf(" Queue OVERFLOW");
        return;
    }
    if (front == -1 && rear == -1)
        front = rear = 0;
    else
        rear = rear + 1;
    queue[rear] = num;
    printf("%d inserted into the queue.", num);
}

void delete_element() {
    int val;
    if (front == -1 || front > rear) {
        printf(" Queue UNDERFLOW");
    } else {
        val = queue[front];
        front = front + 1;
        printf("Deleted element: %d", val);
    }
}
void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue is empty.");
        return;
    }
    printf("Queue elements: ");
    for (i = front; i <= rear; i++)
        printf("%d\n", queue[i]);
}
int main() {
    int choice, num;
    while (1) {
        printf("\nQUEUE OPERATIONS");
        printf("\n1. Insert 2. Delete 3. Display 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &num);
                insert(num);
                break;
            case 2:
                delete_element();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
