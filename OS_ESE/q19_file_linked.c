#include <stdio.h>
struct Block { int id, next; };

int main() {
    int n, i;
    printf("Enter no. of blocks for the file: ");
    scanf("%d", &n);
    struct Block b[n];
    
    for(i=0; i<n; i++) {
        printf("Enter current block ID: ");
        scanf("%d", &b[i].id);
        if(i == n-1) b[i].next = -1; // Last block
        else b[i].next = b[i].id + 1; // Simulation: next block is sequential
    }

    printf("\nFile Allocation Table (Linked):\n");
    for(i=0; i<n; i++) {
        printf("Block: %d  --> Next: %d\n", b[i].id, b[i].next);
    }
    return 0;
}