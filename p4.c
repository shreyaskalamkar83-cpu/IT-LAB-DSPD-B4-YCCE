#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *next;
};

int main() {
struct node *head = NULL;
struct node *temp = NULL;
struct node *newNode;
int n;

printf("Enter numbers (0 to stop):\n");
while(1) {
scanf("%d", &n);
if(n == 0)
break;
newNode = malloc(sizeof(struct node));
newNode->data = n;
newNode->next = NULL;
if(head == NULL) {
head = newNode;
temp = newNode;
} else {
temp->next = newNode;
temp = newNode;
}
}

printf("Linked list: ");
temp = head;
while(temp != NULL) {
printf("%d", temp->data);
if(temp->next != NULL)
printf("->");
temp = temp->next;
}

return 0;
}
