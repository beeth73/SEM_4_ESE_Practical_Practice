#include <stdio.h>
#include <stdbool.h>

#define INF 99999  // Representing Infinity
#define MAX 10     // Maximum number of vertices

// Helper function to find the vertex with the minimum distance 
// from the set of vertices not yet included in the shortest path tree
int findMinDistance(int dist[], bool visited[], int NUMNODES) {
    int min = INF, min_index;

    for (int neighbor = 0; neighbor < NUMNODES; neighbor++) {
        // If vertex is not visited and its distance is smaller than current min
        if (visited[neighbor] == false && dist[neighbor] <= min) {
            min = dist[neighbor];
            min_index = neighbor;
        }
    }
    return min_index;
}

// Function to print the final distance array
void printSolution(int dist[], int NUMNODES, int startNode) {
    printf("\nShortest distances from Source Vertex %d:\n", startNode);
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < NUMNODES; i++) {
        if (dist[i] == INF)
            printf("%d \t INF\n", i);
        else
            printf("%d \t\t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[MAX][MAX], int NUMNODES, int startNode) {
    int dist[NUMNODES];      // Holds the shortest distance from source to i
    bool visited[NUMNODES];  // visited[i] is true if vertex i is finalized

    // Initialize all distances as INFINITY and visited[] as false
    for (int i = 0; i < NUMNODES; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[startNode] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < NUMNODES - 1; count++) {
        
        // Pick the minimum distance vertex from the set of unvisited vertices
        int u = findMinDistance(dist, visited, NUMNODES);

        // Mark the picked vertex as processed
        visited[u] = true;
        printf("Visiting Vertex %d (Current Dist: %d)\n", u, dist[u]);

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int neighbor = 0; neighbor < NUMNODES; neighbor++) {
            /* Update dist[neighbor] only if:
               1. There is an edge from u to neighbor.
               2. neighbor is not visited.
               3. Total weight of path from source to neighbor through u is 
                  smaller than current value of dist[neighbor]. (RELAXATION)
            */
            if (!visited[neighbor] && graph[u][neighbor] && dist[u] != INF 
                && dist[u] + graph[u][neighbor] < dist[neighbor]) {
                
                dist[neighbor] = dist[u] + graph[u][neighbor];
                printf("  -> Relaxing Vertex %d: New Dist = %d\n", neighbor, dist[neighbor]);
            }
        }
    }

    printSolution(dist, NUMNODES, startNode);
}

int main() {
    int NUMNODES, startNode;
    int graph[MAX][MAX];

    printf("Enter the number of vertices (max %d): ", MAX);
    scanf("%d", &NUMNODES);

    printf("Enter the Adjacency Matrix (use 0 if no edge exists):\n");
    for (int i = 0; i < NUMNODES; i++) {
        for (int j = 0; j < NUMNODES; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting (source) vertex (0 to %d): ", NUMNODES - 1);
    scanf("%d", &startNode);

    dijkstra(graph, NUMNODES, startNode);

    return 0;
}