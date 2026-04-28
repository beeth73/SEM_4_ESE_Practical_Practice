#include <stdio.h>

int main() {
    int m, n, i, j;

    printf("--- First Fit Memory Allocation ---\n");

    // 1. Inputs
    printf("Enter number of blocks and processes: ");
    scanf("%d %d", &m, &n);

    int blockSize[m], processSize[n], allocation[n];
    
    printf("Enter sizes of %d blocks:\n", m);
    for(i = 0; i < m; i++) scanf("%d", &blockSize[i]);

    printf("Enter sizes of %d processes:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
        allocation[i] = -1; // Initially not allocated
    }

    // 2. Best Fit Logic
    for (i = 0; i < n; i++) {
        int bestIdx = -1; // Reset for every process
        
        for (j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break; // <--- The most important part! Stop at the first one.
             }
        }

        // Allocate the Best block found
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i]; // Reduce block size (Dynamic)
        }
    }

    // 3. Output
    printf("\nProcess No.\tProcess Size\tBlock No.\tRemaining Block Size\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\t\t%d\n", allocation[i] + 1, blockSize[allocation[i]]);
        else
            printf("Not Allocated\t---\n");
    }
}