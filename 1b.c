#include <stdio.h>

int main() {
    int i, n, search, start = 0, found = 0, mid;
    int arr[100];

    printf("Enter the number of sorted elements of array: ");
    scanf("%d", &n);
    int high = n - 1;

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to find: ");
    scanf("%d", &search);

    while (start <= high) {
        mid = (start + high) / 2;

        printf("\n-------------------\n");
        printf("Start index: %d\n", start);
        printf("End index: %d\n", high);
        printf("Mid index: %d\n", mid);
        printf("Searching in subarray: ");
        for (i = start; i <= high; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n-------------------\n");

        if (arr[mid] == search) {
            printf("\nThe element %d is located at position %d.\n", search, mid + 1);
            found = 1;
            break;
        } else if (search < arr[mid]) {
            high = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    if (found == 0) {
        printf("\nThe element %d is not present in the array.\n", search);
    }

    return 0;
}
