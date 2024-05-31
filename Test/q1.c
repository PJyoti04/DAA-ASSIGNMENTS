//craete  A PROGRAM THAT ACCEPT a graph and two vertices u and v as input implement a function that determine a minimum path from u to v
//Design a program to print a lower priority process among the set of processes using binary heap.

#include<stdio.h>
#include<stdlib.h>

struct vertex{
    int par;
    int dist;
    int status;
};
void dijkstra(int [],int,int);
void extractmin(int,int);
#define INF 9999
#define NIL -1

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
    printf("Vertex\t  Distance\tPath");
    printf("\n%d -> %d \t\t %d\t\t%d ", src, target, dist[target], src);
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
}