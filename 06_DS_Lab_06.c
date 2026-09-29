// Program to implement Merge sort and Bubble Sort

#include <stdio.h>

// Bubble Sort Function
void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


// Merge Function - Combine two sorted parts
void merge(int arr[], int low, int mid, int high)
{
    int temp[100];

    int i = low;
    int j = mid + 1;
    int k = 0;

    // Compare both parts
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    // Remaining elements of left part
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Remaining elements of right part
    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy temp into original array
    for (i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = temp[k];
    }
}


// Merge Sort Function - Divide
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        // Divide left part
        mergeSort(arr, low, mid);

        // Divide right part
        mergeSort(arr, mid + 1, high);

        // Combine
        merge(arr, low, mid, high);
    }
}


// Main Function
int main()
{
    int arr[100];
    int n, choice;
    int i;

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input elements
    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Ask user for sorting choice
    printf("\nChoose Sorting Method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Merge Sort\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);


    // Switch Case
    switch (choice)
    {
        case 1:
            bubbleSort(arr, n);
            printf("\nBubble Sort selected.\n");
            break;

        case 2:
            mergeSort(arr, 0, n - 1);
            printf("\nMerge Sort selected.\n");
            break;


        default:
            printf("\nInvalid choice!\n");
            return 0;
    }


    // Display sorted array
    printf("Sorted Array: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}