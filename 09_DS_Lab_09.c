#include <stdio.h>

int main() {
    int arr[5] = {5, 3, 4, 1, 2};
    int i, j, key;

    // Insertion Sort
    for (i = 1; i < 5; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    // Display sorted array
    printf("Sorted Array: ");

    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}