#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

const int MAXN = 20;   // Maximum number of nodes
const int MAXE = 100;  // Maximum number of edges

int parent[MAXN];
int rankArray[MAXN];   // Array for union by rank

struct Edge {
    int u, v, weight;
};

// Function to initialize the disjoint sets
void InitializeSet(int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        parent[i] = i;
        rankArray[i] = 0; // Initialize rank to 0
    }
}

// Find function with path compression
int Find(int i) {
    if (parent[i] != i) {
        parent[i] = Find(parent[i]);  // Path compression
    }
    return parent[i];
}

// Union by rank function
void Union(int u, int v) {
    int rootU = Find(u);
    int rootV = Find(v);

    if (rootU != rootV) {
        if (rankArray[rootU] > rankArray[rootV]) {
            parent[rootV] = rootU;
        } else if (rankArray[rootU] < rankArray[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rankArray[rootU]++;
        }
    }
}

// Simple bubble sort to sort edges by weight
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

// Kruskal's algorithm to find MST
void KruskalMST(Edge edges[], int numEdges, int numNodes) {
    Edge result[MAXE];  // Array to store MST result
    int e = 0;  // Counter for number of edges in MST
    int i = 0;  // Counter for sorted edges

    InitializeSet(numNodes);  // Initialize the disjoint sets

    SortEdges(edges, numEdges);  // Sort edges by weight

    // Iterate over sorted edges to build the MST
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

    // Input the edges
    for (int i = 0; i < numEdges; i++) {
        cout << "Enter edge " << i + 1 << " (node1 node2 weight): ";
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;

        if (edges[i].u < 0 || edges[i].v < 0 || edges[i].u >= numNodes || edges[i].v >= numNodes || edges[i].weight <= 0) {
            cout << "Invalid edge input.\n";
            return 1;
        }
    }

    // Call Kruskal's algorithm to compute MST
    KruskalMST(edges, numEdges, numNodes);

    return 0;
}