#include <stdio.h>
#include <stdlib.h>

int main() {  // Changed from void to int
    int n, head, total_seek = 0;
    printf("--- FCFS Disk Scheduling ---\n");
    printf("Enter no. of requests: ");
    if (scanf("%d", &n) != 1) return 1;
    
    int req[n];
    printf("Enter requests: ");
    for(int i=0; i<n; i++) scanf("%d", &req[i]);
    
    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Path: %d", head);
    for(int i=0; i<n; i++) {
        total_seek += abs(head - req[i]);
        head = req[i];
        printf(" -> %d", head);
    }
    printf("\nTotal Seek Time: %d\n", total_seek);
    
    return 0; // Added return statement
}