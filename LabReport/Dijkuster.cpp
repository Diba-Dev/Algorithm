//TOPIC : Implementation of Dijkustra 
 
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100; 
int V; 

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[MAXN][MAXN], int src) {
    int dist[MAXN]; // The output array dist[i] holds the shortest distance from src to i
    bool sptSet[MAXN]; // sptSet[i] will be true if vertex i is included in the shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance from the source vertex to itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update the distance value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] if and only if it is not in sptSet, there is an edge from u to v,
            // and the total weight of the path from source to v through u is smaller than the current value of dist[v]
            if (!sptSet[v] && graph[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            cout << i << "\t\tINF\n"; // Use INF for unreachable vertices
        } else {
            cout << i << "\t\t" << dist[i] << "\n";
        }
    }
}

int main() {
    int graph[MAXN][MAXN];

    cout << "Enter number of vertices: ";
    cin >> V;

    if (V <= 0 || V > MAXN) {
        cout << "Invalid number of vertices." << endl;
        return 1;
    }

    // Initialize the graph with infinity weights (except diagonal)
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }

    cout << "Enter number of edges: ";
    int numEdges;
    cin >> numEdges;

    if (numEdges < 0 || numEdges > V * (V - 1) / 2) {
        cout << "Invalid number of edges." << endl;
        return 1;
    }

    cout << "Enter edges (node1 node2 weight):\n";
    for (int i = 0; i < numEdges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        if (u < 0 || u >= V || v < 0 || v >= V || weight < 0) {
            cout << "Invalid edge input.\n";
            return 1;
        }

        graph[u][v] = weight;
        graph[v][u] = weight; // For undirected graph
    }

    cout << "Enter source vertex: ";
    int src;
    cin >> src;

    if (src < 0 || src >= V) {
        cout << "Invalid source vertex." << endl;
        return 1;
    }

    dijkstra(graph, src);

    return 0;
}