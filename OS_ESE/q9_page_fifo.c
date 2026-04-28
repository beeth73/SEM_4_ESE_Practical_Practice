#include <stdio.h>
int main() {
    int n, f, i, j, pf=0, next=0;
    printf("Enter no. of pages and frames: ");
    scanf("%d %d", &n, &f);
    int pg[n], fr[f];
    for(i=0; i<f; i++) fr[i] = -1; // Fill frames with -1
    printf("Enter page string: ");
    for(i=0; i<n; i++) scanf("%d", &pg[i]);

    for(i=0; i<n; i++) {
        int found = 0;
        for(j=0; j<f; j++) if(fr[j] == pg[i]) found = 1;
        
        if(!found) { // Page Fault
            fr[next] = pg[i];
            next = (next + 1) % f; // CIRCULAR POINTER: The oldest one
            pf++;
        }
    }
    printf("Total Page Faults: %d\n", pf);
    return 0;
}