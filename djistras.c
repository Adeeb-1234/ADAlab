#include <stdio.h>

#define V 5
#define INF 99999

// Function to find vertex with minimum distance
int minDistance(int dist[], int visited[])
{
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
    {
        if (visited[v] == 0 && dist[v] < min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print shortest distances
void printSolution(int dist[])
{
    printf("Vertex\tDistance from Source\n");

    for (int i = 0; i < V; i++)
    {
        printf("%d\t%d\n", i, dist[i]);
    }
}

// Dijkstra Algorithm
void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    int visited[V];

    // Initialize distances and visited array
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);

        visited[u] = 1;

        // Update distance value of adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] &&
                graph[u][v] &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main()
{
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int source = 0;

    dijkstra(graph, source);

    return 0;
}
