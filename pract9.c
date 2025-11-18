#include <stdio.h>

#define SIZE 7

int main() {
    int table[SIZE], i, n, key, index;
    
    for (i = 0; i < SIZE; i++)
        table[i] = -1;

    printf("Enter number of keys: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);

        index = key % SIZE;

        while (table[index] != -1) {
            index = (index + 1) % SIZE;
        }

        table[index] = key;
    }

    printf("\nFinal Hash Table:\n");
    for (i = 0; i < SIZE; i++)
        printf("Slot %d: %d\n", i, table[i]);

    return 0;
}
