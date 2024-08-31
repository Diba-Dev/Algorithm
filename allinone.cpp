#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

const int MAXN = 20;
int Graph[MAXN][MAXN];
bool visited[MAXN];

struct Edge {
    int u, v, weight;
};

// Function to initialize the graph matrix with zeros
void InitializeGraph(int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            Graph[i][j] = 0;
        }
    }
}

// Function to set edges between nodes
void SetEdges(int a, int b, int weight = 1) {
    Graph[a][b] = weight;
    Graph[b][a] = weight;
}

// Function to perform BFS traversal
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
            if (Graph[currentNode][i] != 0 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

// Helper function for DFS traversal
void DFSUtil(int node, int numNodes) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < numNodes; i++) {
        if (Graph[node][i] != 0 && !visited[i]) {
            DFSUtil(i, numNodes);
        }
    }
}

// Function to perform DFS traversal
void DFS(int startNode, int numNodes) {
    cout << "DFS Traversal: ";
    DFSUtil(startNode, numNodes);
    cout << endl;
}

// Function to display the adjacency matrix
void DisplayMatrix(int numNodes) {
    cout << "   ";
    for (int j = 0; j < numNodes; j++) {
        cout << j << " ";
    }
    cout << endl;

    for (int i = 0; i < numNodes; i++) {
        cout << i << ": ";
        for (int j = 0; j < numNodes; j++) {
            cout << Graph[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to reset the visited array
void ResetVisited(int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        visited[i] = false;
    }
}

// Function to find the minimum key value
int MinKey(int key[], bool mstSet[], int numNodes) {
    int min = INT_MAX, minIndex;

    for (int i = 0; i < numNodes; i++)
        if (!mstSet[i] && key[i] < min)
            min = key[i], minIndex = i;

    return minIndex;
}

// Function to perform Prim's algorithm
void Prim(int numNodes) {
    int parent[MAXN]; 
    int key[MAXN];   
    bool mstSet[MAXN]; 

    for (int i = 0; i < numNodes; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;     
    parent[0] = -1; 

    for (int count = 0; count < numNodes - 1; count++) {
        int u = MinKey(key, mstSet, numNodes);
        mstSet[u] = true;

        for (int v = 0; v < numNodes; v++)
            if (Graph[u][v] && !mstSet[v] && Graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = Graph[u][v];
            }
    }

    cout << "Prim's MST:\n";
    for (int i = 1; i < numNodes; i++)
        cout << parent[i] << " - " << i << " \t" << Graph[i][parent[i]] << " \n";
}

// Helper function for Kruskal's algorithm to find the set of an element i
int Find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return Find(parent, parent[i]);
}

// Helper function to perform union of two sets
void Union(int parent[], int rank[], int x, int y) {
    int rootX = Find(parent, x);
    int rootY = Find(parent, y);

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

// Function to perform Kruskal's algorithm
void Kruskal(int numNodes, int numEdges) {
    Edge edges[MAXN * MAXN];
    int edgeCount = 0;

    for (int u = 0; u < numNodes; u++) {
        for (int v = u + 1; v < numNodes; v++) {
            if (Graph[u][v] != 0) {
                edges[edgeCount++] = {u, v, Graph[u][v]};
            }
        }
    }

    sort(edges, edges + edgeCount, [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    int parent[MAXN], rank[MAXN];
    for (int i = 0; i < numNodes; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    cout << "Kruskal's MST:\n";
    int mstWeight = 0;
    for (int i = 0; i < edgeCount; i++) {
        int u = Find(parent, edges[i].u);
        int v = Find(parent, edges[i].v);

        if (u != v) {
            cout << edges[i].u << " - " << edges[i].v << " \t" << edges[i].weight << " \n";
            mstWeight += edges[i].weight;
            Union(parent, rank, u, v);
        }
    }
    cout << "Total weight of MST: " << mstWeight << endl;
}

int main() {
    int numNodes, numEdges;

    cout << "Enter the number of Nodes (max " << MAXN << "): ";
    cin >> numNodes;

    if (numNodes > MAXN || numNodes <= 0) {
        cout << "Invalid number of nodes." << endl;
        return 1;
    }

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    InitializeGraph(numNodes);

    for (int i = 0; i < numEdges; i++) {
        int a, b, weight;
        cout << "Enter edge " << i + 1 << " (nodes between 0 and " << numNodes - 1 << ") and weight: ";
        cin >> a >> b >> weight;

        if (a >= 0 && b >= 0 && a < numNodes && b < numNodes) {
            SetEdges(a, b, weight);
        } else {
            cout << "Invalid input, nodes must be within the range.\n";
        }
    }

    int ch;
    do {
        cout << "\nChoose an operation:\n";
        cout << "1) BFS\n";
        cout << "2) DFS\n";
        cout << "3) Prim's MST\n";
        cout << "4) Kruskal's MST\n";
        cout << "5) Display Matrix\n";
        cout << "6) Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        int startNode;
        switch (ch) {
            case 1:
                cout << "Enter the start node (0 - " << numNodes - 1 << "): ";
                cin >> startNode;
                if (startNode >= 0 && startNode < numNodes) {
                    ResetVisited(numNodes);
                    BFS(startNode, numNodes);
                } else {
                    cout << "Invalid start node." << endl;
                }
                break;
            case 2:
                cout << "Enter the start node (0 - " << numNodes - 1 << "): ";
                cin >> startNode;
                if (startNode >= 0 && startNode < numNodes) {
                    ResetVisited(numNodes);
                    DFS(startNode, numNodes);
                } else {
                    cout << "Invalid start node." << endl;
                }
                break;
            case 3:
                Prim(numNodes);
                break;
            case 4:
                Kruskal(numNodes, numEdges);
                break;
            case 5:
                DisplayMatrix(numNodes);
                break;
            case 6:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (ch != 6);

    return 0;
}

