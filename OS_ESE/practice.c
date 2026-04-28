#include <stdio.h>
#include <stdlib.h>

struct Block {
    int id;
    int size;
};

int main() {
    // 1. Setup data
    struct Block memory[] = {{1, 100}, {2, 500}, {3, 200}, {4, 300}};
    int n = 4;
    int processSize = 120;
    int bestIdx = -1;

    // 2. Logic: Find BEST FIT (Smallest block that is >= 120)
    for (int i = 0; i < n; i++) {
        if (memory[i].size >= processSize) {
            if (bestIdx == -1 || memory[i].size < memory[bestIdx].size) {
                bestIdx = i;
            }
        }
    }

    // 3. Output
    if (bestIdx != -1) {
        printf("Process of %d fits best in Block %d (Size: %d)\n", 
                processSize, memory[bestIdx].id, memory[bestIdx].size);
        
        // Bonus: Calculate wasted space (Internal Fragmentation)
        printf("Wasted space: %d\n", memory[bestIdx].size - processSize);
    }

    return 0;
}