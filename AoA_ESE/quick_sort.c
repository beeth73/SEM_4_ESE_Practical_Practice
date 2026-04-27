#include <stdio.h>
/*
How it works:
1. Pick a Pivot: We usually pick the last element, the first element, or a random one. (In this code, we pick the last element).
2. Partitioning: Rearrange the array. This is the hardest part. We use a pointer i to keep track of the "boundary" where elements smaller than the pivot end.
3. Recursive Calls: Once the pivot is in its final "correct" spot, we call Quick Sort recursively for the left side (smaller elements) and the right side (larger elements).*/

// Helper function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* 
   The Heart of Quick Sort: Partitioning
   This function takes the last element as pivot, places
   the pivot element at its correct position in sorted
   array, and places all smaller elements to the left of pivot 
   and all greater elements to the right of pivot.
*/
int partition(int arr[], int low, int high, int totalSize) {
    int pivot = arr[high]; // Picking the last element as the pivot
    int i = (low - 1);    // Index of the smaller element (the boundary)

    printf("\n--- Partitioning with Pivot: %d ---\n", pivot);

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    
    // Finally, swap the pivot into its correct place (at i + 1)
    swap(&arr[i + 1], &arr[high]);
    
    printArray(arr, totalSize);
    return (i + 1); // Return the position where the pivot settled
}

// The recursive function
void quickSort(int arr[], int low, int high, int totalSize) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now at right place */
        int pi = partition(arr, low, high, totalSize);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1, totalSize);
        quickSort(arr, pi + 1, high, totalSize);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nInitial Array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1, n);

    printf("\nFinal Sorted Array: ");
    printArray(arr, n);

    return 0;
}