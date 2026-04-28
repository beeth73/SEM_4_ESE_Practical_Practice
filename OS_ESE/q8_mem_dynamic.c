#include <stdio.h>
int main() {
    int mem[10], i, choice, size, loc;
    for(i=0; i<10; i++) mem[i] = 0; // 0 means free

    while(1) {
        printf("\n1.Allocate 2.Deallocate 3.Exit: ");
        scanf("%d", &choice);
        if(choice==1) {
            printf("Enter location(0-9) and size: ");
            scanf("%d %d", &loc, &size);
            mem[loc] = size;
        } else if(choice==2) {
            printf("Enter location to free: ");
            scanf("%d", &loc);
            mem[loc] = 0;
        } else break;
        
        printf("Memory Status: ");
        for(i=0; i<10; i++) printf("[%d] ", mem[i]);
    }
    return 0;
}