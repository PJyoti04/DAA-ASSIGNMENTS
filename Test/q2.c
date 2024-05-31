//create  A PROGRAM THAT ACCEPT a graph and two vertices u and v as input implement a function that determine a minimum path from u to v

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100
#define INF INT_MAX


int minDistance(int dist[], bool sptSet[], int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}


void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    printf("%d ", j);
}


int printSolution(int dist[], int V, int parent[], int src, int target) {
    printf("Src\tTarget\tCost\tPath");
    printf("\n%d\t%d\t %d\t\t%d ", src, target, dist[target], src);
    printPath(parent, target);
    printf("\n");

    return dist[target];
}


void dijkstra(int graph[MAX][MAX], int src, int target, int V) {
    int dist[MAX];
    bool sptSet[MAX];
    int parent[MAX];

    for (int i = 0; i < V; i++) {
        parent[src] = -1;
        dist[i] = INF;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    printSolution(dist, V, parent, src, target);
}

int main() {
    int V = 4;
    int graph[MAX][MAX] = {
        {0,3,0,0},
        {0,0,5,0},
        {0,0,0,3},
        {0,0,0,0}
    };

    int u = 0; 
    int v = 3;

    dijkstra(graph, u, v, V);

    return 0;
}