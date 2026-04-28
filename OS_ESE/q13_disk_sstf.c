#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, total_seek = 0;
    printf("--- SSTF Disk Scheduling ---\n");
    printf("Enter no. of requests: ");
    scanf("%d", &n);
    
    int req[n];
    int visited[n]; // Tracker: 0 means not visited, 1 means visited
    
    printf("Enter the requests: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        visited[i] = 0; // Initialize all as not visited
    }
    
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Path: %d", head);

    // We need to make 'n' jumps to cover all 'n' requests
    for(int i = 0; i < n; i++) {
        int min_distance = 1000000; // Start with a very large number (Infinity)
        int index = -1;

        // INNER LOOP: Find the closest unvisited request
        for(int j = 0; j < n; j++) {
            if(!visited[j]) {
                int distance = abs(head - req[j]);
                if(distance < min_distance) {
                    min_distance = distance;
                    index = j;
                }
            }
        }

        // MOVEMENT: Now we have the closest one (at 'index')
        visited[index] = 1;           // Mark it so we don't go back
        total_seek += min_distance;   // Add the distance traveled
        head = req[index];            // Move the head to the new position
        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time: %d\n", total_seek);
    return 0;
}