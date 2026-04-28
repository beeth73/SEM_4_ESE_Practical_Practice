#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, size, total_seek = 0, i, j, temp;
    printf("Enter no. of requests and head position: ");
    scanf("%d %d", &n, &head);
    printf("Enter max disk size (e.g., 200): ");
    scanf("%d", &size);

    int req[n+1]; // +1 to add the disk edge if needed
    printf("Enter requests: ");
    for(i=0; i<n; i++) scanf("%d", &req[i]);

    // STEP 1: SORT
    for(i=0; i<n; i++)
        for(j=0; j<n-i-1; j++)
            if(req[j]>req[j+1]) { temp=req[j]; req[j]=req[j+1]; req[j+1]=temp; }

    // STEP 2: FIND HEAD POSITION IN SORTED ARRAY
    int index;
    for(i=0; i<n; i++) if(head < req[i]) { index = i; break; }

    // STEP 3: LOGIC - Go Right to the end, then Left
    printf("Path: %d", head);
    for(i=index; i<n; i++) { // Right to last request
        total_seek += abs(head - req[i]);
        head = req[i];
        printf(" -> %d", head);
    }
    total_seek += abs(size - 1 - head); // Go to absolute end (199)
    printf(" -> %d", size-1);
    head = size - 1;

    for(i=index-1; i>=0; i--) { // Left to remaining
        total_seek += abs(head - req[i]);
        head = req[i];
        printf(" -> %d", head);
    }
    printf("\nTotal Seek: %d\n", total_seek);
    return 0;
}