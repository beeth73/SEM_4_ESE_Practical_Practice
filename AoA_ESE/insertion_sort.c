#include <stdio.h>

/*
How it works:
1. Assume the first element (index 0) is already sorted.
2. Take the next element (let's call it the Key).
3. Compare the Key with the elements in the sorted part (to its left).
4. If the element in the sorted part is larger than the Key, shift that element one position to the right to make a "hole."
5. Repeat the shifting until you find the correct spot for the Key (or reach the start of the array).
6. Insert the Key into the hole.
7. Repeat for all remaining elements.*/


// Helper function to print the array progress
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n) {
    int i, j, key;

    // Outer loop: Starts from the second element (index 1)
    // Why? Because we assume index 0 is a sorted subarray of size 1.
    for (i = 1; i < n; i++) {
        key = arr[i]; // The element we want to 'insert'
        j = i - 1;    // The index of the last element in the sorted part

        printf("\n--- Pass %d (Inserting Key: %d) ---\n", i, key);

        /* 
           Where & How: The Shifting Logic
           Move elements of arr[0..i-1], that are greater than key,
           to one position ahead of their current position.
        */
        while (j >= 0 && arr[j] > key) {
            printf("  %d > %d, shifting %d to the right.\n", arr[j], key, arr[j]);
            arr[j + 1] = arr[j]; // Shift element to the right
            j = j - 1;           // Move to the next element on the left
        }

        // Insert the key into its correct 'hole'
        arr[j + 1] = key; 

        printf("Array after insertion: ");
        printArray(arr, n);
    }
}

int main() {
    int n;

    // User Input: Size
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1) return 1;

    int arr[n];

    // User Input: Elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nInitial Array: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("\nFinal Sorted Array: ");
    printArray(arr, n);

    return 0;
}