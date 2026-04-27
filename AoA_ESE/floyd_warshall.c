#include <stdio.h>

#define INF 99999 // Using a large value for Infinity
#define MAX 10    // Maximum vertices for the lab

void printMatrix(int dist[][MAX], int V) {
    printf("\nShortest Distance Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][MAX], int V) {
    int dist[MAX][MAX];
    int i, j, k;

    // --- STEP 1: Initialize the solution matrix ---
    // Same as input graph matrix initially
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // --- STEP 2: The Triple Nested Loop ---
    // k is the intermediate vertex
    for (k = 0; k < V; k++) {
        printf("\n--- Using Vertex %d as Intermediate ---", k);
        
        for (i = 0; i < V; i++) { // i is the source
            for (j = 0; j < V; j++) { // j is the destination
                
                // If vertex k is on the shortest path from i to j, then update dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        // Optional: print state after each intermediate k to see the "passes"
        // printMatrix(dist, V); 
    }

    printMatrix(dist, V);
}

int main() {
    int V;
    int graph[MAX][MAX];

    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &V);

    printf("Enter the Adjacency Matrix (use 0 for self, %d for No Edge):\n", INF);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            // Logic: if it's not self-loop and user enters 0, make it INF
            if (i != j && graph[i][j] == 0) {
                graph[i][j] = INF;
            }
        }
    }

    floydWarshall(graph, V);

    return 0;
}