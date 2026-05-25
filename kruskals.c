#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Comparator for sorting edges by weight
int compare(const void *a, const void *b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Find function (Disjoint Set - without path compression for simplicity)
int find(int parent[], int i) {
    while(parent[i] != i)
        i = parent[i];
    return i;
}

// Union function
void unionSet(int parent[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[xroot] = yroot;
}

int main() {
    int n, e;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    struct Edge edges[MAX];

    printf("Enter edges (u v weight):\n");
    for(int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Sort edges by weight
    qsort(edges, e, sizeof(struct Edge), compare);

    int parent[MAX];
    for(int i = 0; i < n; i++)
        parent[i] = i;

    int count = 0;
    int minCost = 0;

    printf("\nEdges in MST:\n");

    for(int i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        int set_u = find(parent, u);
        int set_v = find(parent, v);

        if(set_u != set_v) {
            printf("%d - %d : %d\n", u, v, edges[i].weight);
            minCost += edges[i].weight;
            unionSet(parent, set_u, set_v);
            count++;
        }
    }

    printf("\nMinimum Cost = %d\n", minCost);

    return 0;
}
