#include <stdio.h>
int main() {
    int total = 1000, p1 = 400, p2 = 400, p3 = 500;
    printf("Total Memory: %d\n", total);
    printf("Allocating P1(400) and P2(400)...\n");
    int hole1 = p1; // After P1 leaves
    int hole2 = total - (p1 + p2); // Leftover at end (200)
    
    printf("Process P2 finishes. Memory is now fragmented.\n");
    printf("Hole 1: %d, Hole 2: %d. Total Free: %d\n", hole1, hole2, hole1+hole2);
    
    if(p3 > hole1 && p3 > hole2 && p3 <= (hole1+hole2)) {
        printf("P3(%d) arrives. It cannot fit because memory is not contiguous!\n", p3);
        printf("RESULT: External Fragmentation Demonstrated.\n");
    }
    return 0;
}