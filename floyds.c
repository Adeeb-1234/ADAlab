#include <stdio.h>

#define INF 99999

int main() {
    int n, i, j, k;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int dist[n][n];

    // Input adjacency matrix
    printf("Enter the adjacency matrix:\n");
    printf("(Enter %d if there is no direct edge)\n", INF);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("Distance from %d to %d: ", i, j);
            scanf("%d", &dist[i][j]);
        }
    }

    // Floyd's Algorithm
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Output result
    printf("\nShortest distance matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
