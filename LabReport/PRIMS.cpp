//TOPIC : Implementation of Prims
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 20;
int Graph[MAXN][MAXN], key[MAXN], parent[MAXN];
bool inMST[MAXN];
int numNodes;

// Initialize the graph with infinity weights (except diagonal)
void InitializeGraph() {
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            Graph[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }
}

// Find the vertex with the minimum key value
int MinKey() {
    int minIndex = -1, minValue = INT_MAX;
    for (int i = 0; i < numNodes; i++) {
        if (!inMST[i] && key[i] < minValue) {
            minValue = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Prim's Algorithm to find MST
void PrimMST() {
    // Manually filling the key array with INT_MAX
    for (int i = 0; i < numNodes; i++) {
        key[i] = INT_MAX;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < numNodes - 1; i++) {
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

int main() {
    int numEdges;
    cout << "Enter number of nodes: ";
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
        Graph[a][b] = Graph[b][a] = weight;
    }

    PrimMST();
    DisplayMST();

    return 0;
}
