#include <stdio.h>

int main() {
    int m, n, i, j;

    printf("--- Fixed Partition Memory Allocation ---\n");
    
    // 1. Get Memory Blocks
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    int blockSize[m], blockOccupied[m];
    
    printf("Enter size of each block:\n");
    for (i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
        blockOccupied[i] = 0; // Initialize all blocks as empty
    }

    // 2. Get Processes
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    int processSize[n], allocation[n], fragmentation[n];

    printf("Enter size of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
        allocation[i] = -1; // Initialize as not allocated
    }

    // 3. Allocation Logic
    for (i = 0; i < n; i++) { // For every process
        for (j = 0; j < m; j++) { // Check every block
            if (!blockOccupied[j] && blockSize[j] >= processSize[i]) {
                // If block is free and big enough
                allocation[i] = j;
                blockOccupied[j] = 1; // Mark block as filled
                fragmentation[i] = blockSize[j] - processSize[i];
                break; // Move to the next process
            }
        }
    }

    // 4. Output Table
    printf("\nProcess No.\tProcess Size\tBlock No.\tFragmentation\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\t\t%d\n", allocation[i] + 1, fragmentation[i]);
        } else {
            printf("Not Allocated\t---\n");
        }
    }
}