//TOPIC : Implementation of prims law
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 20;
int Graph[MAXN][MAXN];
bool inMST[MAXN];
int key[MAXN];
int parent[MAXN];
int numNodes;

// Initialize the graph with infinity weights (except diagonal)
void InitializeGraph() {
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            if (i == j) {
                Graph[i][j] = 0;
            } else {
                Graph[i][j] = INT_MAX;
            }
        }
    }
}

// Set edges
void SetEdges(int a, int b, int weight) {
    Graph[a][b] = weight;
    Graph[b][a] = weight;
}

// Find the vertex with the minimum key value
int MinKey() {
    int min = INT_MAX, minIndex;
    for (int i = 0; i < numNodes; i++) {
        if (!inMST[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Prim's Algorithm
void PrimMST() {
    // Initialize arrays
    for (int i = 0; i < numNodes; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
    }
    key[0] = 0; // Start from the first node
    parent[0] = -1; // First node is the root of MST

    for (int count = 0; count < numNodes - 1; count++) {
        int u = MinKey();
        inMST[u] = true;

        for (int v = 0; v < numNodes; v++) {
            if (Graph[u][v] && !inMST[v] && Graph[u][v] < key[v]) {
                key[v] = Graph[u][v];
                parent[v] = u;
            }
        }
    }
}

// Display the MST
void DisplayMST() {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < numNodes; i++) {
        cout << parent[i] << " - " << i << " \t" << Graph[i][parent[i]] << endl;
    }
}

// Function to display the adjacency matrix
void DisplayAdjacencyMatrix() {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            if (Graph[i][j] == INT_MAX) {
                cout << "INF" << "\t";
            } else {
                cout << Graph[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main() {
    int numEdges;

    cout << "Enter number of nodes (max " << MAXN << "): ";
    cin >> numNodes;

    if (numNodes <= 0 || numNodes > MAXN) {
        cout << "Invalid number of nodes." << endl;
        return 1;
    }

    cout << "Enter number of edges: ";
    cin >> numEdges;

    InitializeGraph();

    for (int i = 0; i < numEdges; i++) {
        int a, b, weight;
        cout << "Enter edge " << i + 1 << " (node1 node2 weight): ";
        cin >> a >> b >> weight;

        if (a >= 0 && b >= 0 && a < numNodes && b < numNodes && weight > 0) {
            SetEdges(a, b, weight);
        } else {
            cout << "Invalid input.\n";
        }
    }

    // Ask the user if they want to display the adjacency matrix
    char displayMatrix;
    cout << "Do you want to display the adjacency matrix? (y/n): ";
    cin >> displayMatrix;

    if (displayMatrix == 'y' || displayMatrix == 'Y') {
        DisplayAdjacencyMatrix();
    }

    PrimMST();
    DisplayMST();

    return 0;
}
