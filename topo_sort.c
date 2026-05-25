#include <stdio.h>
#define MAX 100

int n; // number of vertices
int adj[MAX][MAX]; // adjacency matrix

void topologicalSort() {
    int indegree[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int topo[MAX], k = 0;

    // Step 1: Calculate indegree of each vertex
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Add all vertices with indegree 0 to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Step 3: Process the queue
    while (front < rear) {
        int u = queue[front++]; // remove source
        topo[k++] = u;

        // Reduce indegree of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    // Step 4: Check for cycle
    if (k != n) {
        printf("Graph has a cycle! Topological sort not possible.\n");
    } else {
        printf("Topological Order:\n");
        for (int i = 0; i < k; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort();

    return 0;
}

