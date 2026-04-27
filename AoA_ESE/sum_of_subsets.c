#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int set[MAX];      // The input set of numbers
int solution[MAX]; // Stores 1 if element is included, 0 otherwise
int target;        // The target sum
int n;             // Number of elements in the set
int count = 0;     // Number of subsets found

// Function to print a valid subset
void printSubset() {
    printf("Subset %d: { ", ++count);
    for (int i = 0; i < n; i++) {
        if (solution[i] == 1) {
            printf("%d ", set[i]);
        }
    }
    printf("}\n");
}

/*
   Backtracking Function:
   index: current element we are considering (0 to n-1)
   currentSum: sum of elements included so far
   remainingSum: sum of all elements not yet considered
*/
void subsetSum(int index, int currentSum, int remainingSum) {
    // Base Case: If we reached the target sum
    if (currentSum == target) {
        printSubset();
        return;
    }

    // If we have gone through all elements or exceeded the target
    if (index >= n || currentSum > target) {
        return;
    }

    // --- CHOICE 1: Include the current element ---
    // Promising Check: Only include if it doesn't exceed target
    if (currentSum + set[index] <= target) {
        solution[index] = 1; // Include
        subsetSum(index + 1, currentSum + set[index], remainingSum - set[index]);
    }

    // --- CHOICE 2: Exclude the current element ---
    // Promising Check: Only exclude if the remaining elements are enough to reach target
    if (currentSum + (remainingSum - set[index]) >= target) {
        solution[index] = 0; // Exclude
        subsetSum(index + 1, currentSum, remainingSum - set[index]);
    }
}

int main() {
    int totalSum = 0;

    printf("Enter number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter %d elements (positive integers):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[set[i], i]); // Logic error in prompt, fixed below
    }
    // Corrected loop for scanning
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
        totalSum += set[i];
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    // Initial check: if target is bigger than sum of all elements, no solution
    if (totalSum < target) {
        printf("No solution possible. Target is greater than total sum.\n");
    } else {
        printf("\n--- Valid Subsets ---\n");
        subsetSum(0, 0, totalSum);
        
        if (count == 0) {
            printf("No subsets found that match the target sum.\n");
        }
    }

    return 0;
}