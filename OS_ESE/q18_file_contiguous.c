#include <stdio.h>
int main() {
    int disk[100] = {0}, start, len, n;
    printf("Enter no. of files: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        printf("Enter start block and length for File %d: ", i+1);
        scanf("%d %d", &start, &len);
        int can_allocate = 1;
        for(int j=start; j<start+len; j++) if(disk[j]) can_allocate = 0;
        
        if(can_allocate) {
            for(int j=start; j<start+len; j++) disk[j] = 1;
            printf("Allocated!\n");
        } else printf("Conflict! Block already used.\n");
    }
    return 0;
}