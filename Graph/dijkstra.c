#include<stdio.h.>
#include<stdlib.h>
#include<limits.h>

struct vertex{
    int par;
    int dist;
    int v_num;
    int status;
};
struct vertex vert[5];
void dijkstra(int [][5],int );
int extract_min(struct vertex Q[]);
int initialize_single_source(int adjmatrix[][5],int s);

#define INF 9999
#define NIL -1
int main(){
    int i,j;
    int G[5][5]={{0,10,3,0,0},{0,0,1,2,0},{0,4,0,8,2},{0,0,0,0,7},{0,0,0,9,0}};
    int s;
    s=0;
    printf("The adjancency matrix of the graph is \n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%d\t",G[i][j]);
        }
    }
    dijkstra(G,s);
    return 0;
}

void dijkstra(int G[][5],int s)
{
    int i,u,v;
    for(i=0;i<5;i++)
    {
        vert[i].dist=INF;
        vert[i].par=NIL;
        vert[i].v_num=i;
    }
    vert[i].dist=0;
    struct vertex Q[5];

    for(i=0;i<5;i++){
        Q[i].dist=vert[i].dist;
        Q[i].par=vert[i].par;
        Q[i].v_num=i;
        Q[i].status=1;
    }
    Q[s].dist=0;
    while((u=extract_min(Q)!=-1)){
        for(v=0;v<5;v++){
            if(v==u){
                continue;
            }
            if(G[u][v] !=0 && Q[v].dist>Q[u].dist +G[u][v])
            {
                Q[v].dist=Q[u].dist+G[u][v];
                Q[v].par=u;
            }
        }
        printf("The shortest distance from source to vertex %d is=%d \n",u,Q[u].dist);
    }
}
int extract_min(struct vertex Q[]) {
    int size = 4;
    int min_index = 0;
    for (int i = 0; i < size; i++) {
        if (Q[i].dist < Q[min_index].dist) {
            min_index = i;
        }
    }
    int min_value = Q[min_index].dist;
    Q[min_index] = Q[size - 1];
    size--;
    return min_value;
}