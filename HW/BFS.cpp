//TOPIC : Implementation of BFS
 
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 20;
int Graph[MAXN][MAXN];
bool visited[MAXN];

// Initialize the graph with 0
void InitializeGraph(int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            Graph[i][j] = 0;
        }
    }
}

// Set edges
void SetEdges(int a, int b) {
    Graph[a][b] = 1;
    Graph[b][a] = 1;
}

// BFS traversal
void BFS(int startNode, int numNodes) {
    int queue[MAXN];
    int front = 0, rear = 0;
    queue[rear++] = startNode;
    visited[startNode] = true;

    cout << "BFS Traversal: ";

    while (front < rear) {
        int currentNode = queue[front++];
        cout << currentNode << " ";

        for (int i = 0; i < numNodes; i++) {
            if (Graph[currentNode][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

// Display the adjacency matrix
void DisplayMatrix(int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        cout << i << ": ";
        for (int j = 0; j < numNodes; j++) {
            cout << Graph[i][j] << " ";
        }
        cout << endl;
    }
}

// Reset visited array
void ResetVisited(int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        visited[i] = false;
    }
}

int main() {
    int numNodes, numEdges;

    cout << "Enter number of nodes (max " << MAXN << "): ";
    cin >> numNodes;

    if (numNodes <= 0 || numNodes > MAXN) {
        cout << "Invalid number of nodes." << endl;
        return 1;
    }

    cout << "Enter number of edges: ";
    cin >> numEdges;

    InitializeGraph(numNodes);

    for (int i = 0; i < numEdges; i++) {
        int a, b;
        cout << "Enter edge " << i + 1 << " (nodes between 0 and " << numNodes - 1 << "): ";
        cin >> a >> b;

        if (a >= 0 && b >= 0 && a < numNodes && b < numNodes) {
            SetEdges(a, b);
        } else {
            cout << "Invalid input, nodes must be within range.\n";
        }
    }

    DisplayMatrix(numNodes);

    int startNode;
    cout << "Enter start node for BFS (0 - " << numNodes - 1 << "): ";
    cin >> startNode;

    if (startNode >= 0 && startNode < numNodes) {
        ResetVisited(numNodes);
        BFS(startNode, numNodes);
    } else {
        cout << "Invalid start node." << endl;
    }

    return 0;
}
