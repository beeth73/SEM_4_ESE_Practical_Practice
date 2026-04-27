/* How it works:
1. Divide: Find the middle point and split the array into two halves.
2. Conquer: Recursively call mergeSort for the left half and the right half.
3. Combine (Merge): Merge the two sorted halves back into a single sorted array. This is the "brain" of the algorithm.*/

/*Order of writing
1. printRange()    ← helper, needs nothing
2. merge()         ← needs printRange
3. mergeSort()     ← needs merge
4. main()          ← needs mergeSort*/

/*Variable Cheatsheet
In mergeSort:
    l = left boundary of current piece
    r = right boundary of current piece
    m = middle index

In merge:
    l, m, r = same as above
    n1      = size of left half  = m - l + 1
    n2      = size of right half = r - m
    L[]     = temporary copy of left half
    R[]     = temporary copy of right half
    i       = pointer walking through L
    j       = pointer walking through R
    k       = pointer walking through arr (where you write)*/

#include <stdio.h>
#include <stdlib.h>

// Helper function to print a specific segment of the array
void printRange(int arr[], int low, int high) {
    for (int i = low; i <= high; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// The "Merge" function: This is where the actual sorting happens
/*
function merge(arr, l, m, r):

    // Step 1: figure out sizes of both halves
    n1 = size of left half
    n2 = size of right half

    // Step 2: copy both halves into temporary arrays
    copy arr[l..m]   into L[]
    copy arr[m+1..r] into R[]

    // Step 3: compare front of L and front of R
    //         pick the smaller one, put it back in arr
    i = 0, j = 0, k = l
    while both halves still have elements:
        if L[i] <= R[j]:
            arr[k] = L[i]
            move i forward
        else:
            arr[k] = R[j]
            move j forward
        move k forward

    // Step 4: copy whatever is left over
    copy remaining L[] into arr
    copy remaining R[] into arr*/

void merge(int arr[], int l, int m, int r, int n) {
    int i, j, k;
    int n1 = m - l + 1; // Size of the left subarray
    int n2 = r - m;     // Size of the right subarray

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    printf("Merging: [ ");
    printRange(L, 0, n1 - 1);
    printf(" ] and [ ");
    printRange(R, 0, n2 - 1);
    printf(" ]\n");

    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// The recursive function that divides the array
void mergeSort(int arr[], int l, int r, int n) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m, n);
        mergeSort(arr, m + 1, r, n);

        // Merge the sorted halves
        merge(arr, l, m, r, n);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 1;

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nInitial Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n\n");

    // Call mergeSort: starts from index 0 to n-1
    mergeSort(arr, 0, n - 1, n);

    printf("\nFinal Sorted Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}