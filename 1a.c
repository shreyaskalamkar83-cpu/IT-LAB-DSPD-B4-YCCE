#include <stdio.h>

int main() {
    int arr[100], i, n;
    int sum_even = 0, sum_odd = 0;

    printf("enter the size of the array: ");
    scanf("%d", &n);

    printf("enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum_even = sum_even + arr[i];
        } else {
            sum_odd = sum_odd + arr[i];
        }
    }

    printf("sum of elements at even positions = %d\n", sum_even);
    printf("sum of elements at odd positions = %d\n", sum_odd);

    return 0;
}
