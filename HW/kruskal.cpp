#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

const int MAXN = 20;
const int MAXE = 100; // Assume a maximum number of edges
int parent[MAXN];
int rankArray[MAXN]; // Renamed rank to rankArray

struct Edge {
    int u, v, weight;
};

// Initialize disjoint set
void InitializeSet(int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        parent[i] = i;
        rankArray[i] = 0; // Updated to rankArray
    }
}

// Find function with path compression
int Find(int i) {
    if (parent[i] != i) {
        parent[i] = Find(parent[i]);
    }
    return parent[i];
}

// Union function by rank
void Union(int u, int v) {
    int rootU = Find(u);
    int rootV = Find(v);

    if (rootU != rootV) {
        if (rankArray[rootU] > rankArray[rootV]) { // Updated to rankArray
            parent[rootV] = rootU;
        } else if (rankArray[rootU] < rankArray[rootV]) { // Updated to rankArray
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rankArray[rootU]++; // Updated to rankArray
        }
    }
}

// Sort edges based on weight using a simple bubble sort
void SortEdges(Edge edges[], int numEdges) {
    for (int i = 0; i < numEdges - 1; i++) {
        for (int j = 0; j < numEdges - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Kruskal's Algorithm
void KruskalMST(Edge edges[], int numEdges, int numNodes) {
    Edge result[MAXE];
    int e = 0; // Index for result[]
    int i = 0; // Initial index of sorted edges

    // Initialize disjoint sets
    InitializeSet(numNodes);

    // Sort all edges in non-decreasing order of their weight
    SortEdges(edges, numEdges);

    // Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far
    while (e < numNodes - 1 && i < numEdges) {
        Edge nextEdge = edges[i++];
        int x = Find(nextEdge.u);
        int y = Find(nextEdge.v);

        // If including this edge does not cause a cycle
        if (x != y) {
            result[e++] = nextEdge;
            Union(x, y);
        }
    }

    // Display the MST
    cout << "Edge \tWeight\n";
    for (int i = 0; i < e; i++) {
        cout << result[i].u << " - " << result[i].v << " \t" << result[i].weight << endl;
    }
}

int main() {
    int numNodes, numEdges;
    Edge edges[MAXE];

    cout << "Enter number of nodes (max " << MAXN << "): ";
    cin >> numNodes;

    if (numNodes <= 0 || numNodes > MAXN) {
        cout << "Invalid number of nodes." << endl;
        return 1;
    }

    cout << "Enter number of edges: ";
    cin >> numEdges;

    if (numEdges > MAXE) {
        cout << "Too many edges." << endl;
        return 1;
    }

    for (int i = 0; i < numEdges; i++) {
        cout << "Enter edge " << i + 1 << " (node1 node2 weight): ";
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;

        if (edges[i].u < 0 || edges[i].v < 0 || edges[i].u >= numNodes || edges[i].v >= numNodes || edges[i].weight <= 0) {
            cout << "Invalid edge input.\n";
            return 1;
        }
    }

    KruskalMST(edges, numEdges, numNodes);

    return 0;
}
