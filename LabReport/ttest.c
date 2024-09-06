#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Maximum number of vertices in the graph
#define MAX_V 100

// A utility function to find the vertex with
// minimum key value from the set of vertices
// not yet included in MST
int minKey(int key[], bool mstSet[], int V)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// A utility function to print the
// constructed MST stored in parent[]
void printMST(int parent[], int graph[MAX_V][MAX_V], int V)
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to construct and print MST for
// a graph represented using adjacency matrix
void primMST(int graph[MAX_V][MAX_V], int V)
{
    int parent[MAX_V];
    int key[MAX_V];
    bool mstSet[MAX_V];

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, V);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph, V);
}

// Driver's code
int main()
{
    int V;
    int graph[MAX_V][MAX_V];

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Ensure the number of vertices does not exceed the maximum limit
    if (V > MAX_V) {
        printf("Number of vertices exceeds the maximum limit of %d\n", MAX_V);
        return 1;
    }

    printf("Enter the adjacency matrix (Enter 0 for no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("Weight of edge from %d to %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    // Print the solution
    primMST(graph, V);

    return 0;
}