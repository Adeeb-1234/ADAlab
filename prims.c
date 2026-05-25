#include <stdio.h>
#define MAX 100
#define INF 999999

int main() {
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[MAX][MAX];

    printf("Enter the cost adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            // Replace 0 with INF (no edge)
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    int visited[MAX] = {0};
    visited[0] = 1;  // Start from vertex 0

    int edges = 0;
    int min_cost = 0;

    printf("\nEdges in MST:\n");

    while(edges < n - 1) {
        int min = INF;
        int a = -1, b = -1;

        for(i = 0; i < n; i++) {
            if(visited[i]) {
                for(j = 0; j < n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if(a != -1 && b != -1) {
            printf("%d - %d : %d\n", a, b, min);
            min_cost += min;
            visited[b] = 1;
            edges++;
        }
    }

    printf("\nMinimum Cost = %d\n", min_cost);

    return 0;
}
