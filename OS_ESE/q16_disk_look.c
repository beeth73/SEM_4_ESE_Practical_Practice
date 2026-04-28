#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, j, temp, total = 0;
    printf("--- LOOK Disk Scheduling ---\n");
    printf("Enter no. of requests and head position: ");
    scanf("%d %d", &n, &head);
    int req[n];
    printf("Enter requests: ");
    for(i=0; i<n; i++) scanf("%d", &req[i]);

    // 1. Sort requests
    for(i=0; i<n; i++)
        for(j=0; j<n-i-1; j++)
            if(req[j]>req[j+1]){ temp=req[j]; req[j]=req[j+1]; req[j+1]=temp; }

    // 2. Find head's position
    int index;
    for(i=0; i<n; i++) if(head < req[i]) { index = i; break; }

    // 3. Logic: Go Right to Max request, then Left to Min request
    printf("Path: %d", head);
    for(i=index; i<n; i++) {
        total += abs(head - req[i]);
        head = req[i];
        printf(" -> %d", head);
    }
    for(i=index-1; i>=0; i--) {
        total += abs(head - req[i]);
        head = req[i];
        printf(" -> %d", head);
    }
    printf("\nTotal Seek Time: %d\n", total);
    return 0;
}