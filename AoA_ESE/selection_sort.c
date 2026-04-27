#include <stdio.h>

/*
How it works:
1. Maintain two parts in the array: the sorted part (left) and the unsorted part (right).
2. Initially, the sorted part is empty.
3. In every "pass," find the smallest element in the unsorted part.
4. Swap that smallest element with the first element of the unsorted part.
5. Move the boundary between the sorted and unsorted parts one position to the right.
6. Repeat until the array is fully sorted.*/

// Helper function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    // Outer loop: One by one move the boundary of the unsorted subarray
    // i goes up to n-2 because the last element will automatically be the largest
    for (i = 0; i < n - 1; i++) {
        
        // Assume the current position 'i' holds the minimum element
        min_idx = i;
        printf("\n--- Pass %d (Finding min starting from index %d) ---\n", i + 1, i);

        // Inner loop: Find the actual minimum element in the remaining unsorted array
        for (j = i + 1; j < n; j++) {
            // Compare current element with the current known minimum
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Update the index of the minimum element
            }
        }

        // How we swap: Put the found minimum element at the correct position 'i'
        // We only swap if a smaller element was actually found
        if (min_idx != i) {
            printf("Found smaller element %d at index %d. Swapping with %d.\n", arr[min_idx], min_idx, arr[i]);
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        } else {
            printf("Current element %d is already the minimum for this pass.\n", arr[i]);
        }

        // Show the state of the array after this pass
        printf("Array after Pass %d: ", i + 1);
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

    selectionSort(arr, n);

    printf("\nFinal Sorted Array: ");
    printArray(arr, n);

    return 0;
}