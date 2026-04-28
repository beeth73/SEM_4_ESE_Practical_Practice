#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, max, i, j, temp, total = 0;
    printf("Enter no. of requests, head position, and max disk size: ");
    scanf("%d %d %d", &n, &head, &max);
    int req[n+2]; // Extra space for 0 and max-1
    printf("Enter requests: ");
    for(i=0; i<n; i++) scanf("%d", &req[i]);

    // Add boundaries for C-SCAN
    req[n] = 0; req[n+1] = max - 1; n += 2;

    // STEP 1: Sort
    for(i=0; i<n; i++)
        for(j=0; j<n-i-1; j++)
            if(req[j]>req[j+1]){ temp=req[j]; req[j]=req[j+1]; req[j+1]=temp; }

    // STEP 2: Find where head fits
    int pos;
    for(i=0; i<n; i++) if(head < req[i]) { pos = i; break; }

    // STEP 3: LOGIC - Go Right to end, jump to 0, go Right again
    printf("Path: %d", head);
    for(i=pos; i<n; i++) { // Right to 199
        total += abs(head - req[i]);
        head = req[i];
        printf(" -> %d", head);
    }
    // The "Circular" Jump
    total += abs(head - 0); // Distance from 199 to 0
    head = 0;
    printf(" -> %d", head);

    for(i=0; i<pos; i++) { // Right from 0 to last request before original head
        total += abs(head - req[i]);
        head = req[i];
        printf(" -> %d", head);
    }
    printf("\nTotal Seek: %d\n", total);
    return 0;
}