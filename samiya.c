#include <stdio.h>

int queue[100];
int front = 0, back = 0;

void push(int var) {
    queue[back] = var;
    back++;
}

void pop() {
    queue[front] = 0;
    front++;
}

int visited[10] = {1}; // Initialize to 1

int main() {
    int N;
    printf("Enter the number of nodes: ");
    scanf("%d", &N);
    int graph[N][N];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int startNode;
    printf("Enter the starting node: ");
    scanf("%d", &startNode);
    if (startNode >= 1 && startNode <= N) {
        push(startNode);
        visited[startNode - 1] = 0;

        while (front != back) {
            int current = queue[front];
            printf("%d ", current);
            pop();

            for (int i = 0; i < N; i++) {
                if (graph[current - 1][i] == 1 && visited[i] == 1) {
                    visited[i] = 0;
                    push(i + 1);
                }
            }
        }
    } else {
        printf("Invalid starting node. Please enter a node between 1 and %d.\n", N);
    }

    return 0;
}