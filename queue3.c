#include <stdio.h>
#include <stdlib.h>
#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

void insert(char ch) {
    if (rear == MAX - 1) {
        printf("Overflow! Queue is full.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = ch;
        printf("Inserted: %c\n", ch);
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Underflow! Queue is empty.\n");
    } else {
        printf("Deleted: %c\n", queue[front++]);
        if (front > rear) {
            front = rear = -1;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue status: ");
        for (int i = front; i <= rear; i++) {
            printf("%c ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    char ch;

    while (1) {
        printf("\n---MENU---\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &ch);
                insert(ch);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
