#include <stdio.h>
#include <stdbool.h> // Required for the boolean 'swapped' flag

/*
#. The Problem: Bubble Sort
The goal is to sort an array in ascending order.
How it works:
1. Compare two adjacent elements.
2. If the left element is greater than the right, swap them.
3. Move to the next pair and repeat until the end of the array.
4. After the first "pass," the largest element will have "bubbled up" to the last position.
5. Repeat the process for the remaining unsorted elements.*/

// Function to print the array to show the progress of each pass
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    bool swapped;

    // Outer loop: Number of passes
    // Why n-1? Because after n-1 passes, the last element is automatically sorted.
    for (i = 0; i < n - 1; i++) {
        swapped = false; // Reset flag at the start of every pass
        printf("\n--- Pass %d ---\n", i + 1);

        // Inner loop: Comparing adjacent elements
        // Why n-i-1? Because after 'i' passes, 'i' elements at the end are already sorted.
        for (j = 0; j < n - i - 1; j++) {
            
            // Where the comparison happens
            if (arr[j] > arr[j + 1]) {
                // How we swap: Using a temporary variable
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swapped = true; // Mark that we did a swap
            }
            // Optional: Print state after every single comparison
            // printArray(arr, n); 
        }

        // Show the state of the array after this pass is completed
        printArray(arr, n);

        // Optimization: If no two elements were swapped in the inner loop, then break
        if (swapped == false) {
            printf("No swaps occurred. Array is already sorted!\n");
            break;
        }
    }
}

int main() {
    int n;

    // User Input: Size of the array
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1) return 1;

    int arr[n];

    // User Input: Array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nInitial Array: ");
    printArray(arr, n);

    // Call the sorting function
    bubbleSort(arr, n);

    printf("\nFinal Sorted Array: ");
    printArray(arr, n);

    return 0;
}