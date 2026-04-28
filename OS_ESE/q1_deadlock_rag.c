#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int adj[MAX][MAX]; // Adjacency Matrix
int visited[MAX];  // Global visited tracker
int onStack[MAX];  // Tracker for the current DFS path
int n;             // Total number of nodes (Processes + Resources)

// DFS Function to detect cycle
bool hasCycle(int u) {
    visited[u] = 1;
    onStack[u] = 1;

    for (int v = 0; v < n; v++) {
        if (adj[u][v]) { // If there is an edge from u to v
            if (onStack[v]) {
                // We found a node that is already on the current path!
                return true; 
            }
            if (!visited[v] && hasCycle(v)) {
                return true;
            }
        }
    }

    onStack[u] = 0; // Remove from stack as we go back
    return false;
}

int main() {
    int edges, u, v;

    printf("--- Deadlock Detection using RAG ---\n");
    printf("Enter total number of nodes (Processes + Resources): ");
    scanf("%d", &n);

    printf("Enter total number of edges: ");
    scanf("%d", &edges);

    // Initialize matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) adj[i][j] = 0;
        visited[i] = 0;
        onStack[i] = 0;
    }

    printf("Enter edges (source destination):\n");
    printf("Hint: If P0(0) requests R0(1), enter: 0 1\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    bool deadlock = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycle(i)) {
                deadlock = true;
                break;
            }
        }
    }

    if (deadlock) {
        printf("\nRESULT: Deadlock Detected! (Cycle exists in RAG)\n");
    } else {
        printf("\nRESULT: No Deadlock. (No cycle in RAG)\n");
    }

    return 0;
} 