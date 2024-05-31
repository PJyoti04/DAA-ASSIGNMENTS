#include <stdio.h>
#include <stdlib.h>

#define V 5
#define INF 9999
#define NIL -1

struct vertex {
    int dist;
    int par;
    int v_num;
    int status; // 0 for unvisited, 1 for visited
};

struct vertex vert[V];

void dijkstra(int graph[V][V], int source);
int extract_min(struct vertex Q[], int size);

int main() {
    int i, j;
    int graph[V][V] = {
        {0, 10, 5, 0, 0},
        {0, 0, 2, 0, 1},
        {0, 3, 0, 2, 9},
        {7, 0, 0, 0, 6},
        {0, 1, 0, 4, 0}
    };

    printf("The adjacency matrix of the graph is:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    int source = 0; 
    dijkstra(graph, source);

    printf("\nVertex\tDistance from Source\tParent\n");
    for (i = 0; i < V; i++) {
        printf("%d\t\t%d\t\t%d\n", vert[i].v_num, vert[i].dist, vert[i].par);
    }

    return 0;
}

void dijkstra(int graph[V][V], int source) {
    int i, count;
    for (i = 0; i < V; i++) {
        vert[i].dist = INF;
        vert[i].par = NIL;
        vert[i].v_num = i;
        vert[i].status = 0;
    }
    vert[source].dist = 0;

    for (count = 0; count < V - 1; count++) {
        int u = extract_min(vert, V);
        vert[u].status = 1;

        for (int v = 0; v < V; v++) {
            if (!vert[v].status && graph[u][v] && vert[u].dist != INF 
                && vert[u].dist + graph[u][v] < vert[v].dist) {
                vert[v].dist = vert[u].dist + graph[u][v];
                vert[v].par = u;
            }
        }
    }
}

int extract_min(struct vertex Q[], int size) {
    int min = INF, min_index;

    for (int v = 0; v < size; v++) {
        if (Q[v].status == 0 && Q[v].dist <= min) {
            min = Q[v].dist;
            min_index = v;
        }
    }
    return min_index;
}