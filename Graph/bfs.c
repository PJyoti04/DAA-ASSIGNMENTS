#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node{
    char color;
    int distance;
    int parent;
};
struct node graph[8];
int front=-1;
int rear=-1;

int n=8;
int Q[8];

void enqueue(int x)
{
    if(rear==n-1)
        printf("Queue is full\n");
    else
    {
        if(front==-1)
            front=0;
        rear=rear+1;
        Q[rear]=x;
    }
}

int dequeue()
{
    int x;
    if(front==-1 || front>rear)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        x=Q[front];
        front=front+1;
        return x;
    }
}

void bfs(int adjMatrix[][8],int s)
{
    int i;
    for(i=0;i<n;i++)
    {
        graph[i].color='W';
        graph[i].distance=INT_MAX;
        graph[i].parent=-1;
    }
    graph[s].color='G';
    graph[s].distance=0;
    graph[s].parent=-1;
    enqueue(s);
    while(front<=rear)
    {
        int u=dequeue();
        printf("%d ",u);
        for(i=0;i<n;i++)
        {
            if(graph[i].color=='W' && i!=u)
            {
                graph[i].color='G';
                graph[i].distance=graph[u].distance+1;
                graph[i].parent=u;
                enqueue(i);
            }
        }
        graph[u].color='B';
    }
}
int main(){
    int i,j;
    int adjMatrix[8][8]={{0,1,1,0,0,0,0,0},{1,0,0,0,0,0,0,0},{1,0,0,1,0,0,0,0},{0,0,1,0,1,1,0,0},{0,0,0,1,0,1,1,0},{0,0,0,1,1,0,1,1},{0,0,0,0,1,1,0,1},{0,0,0,0,0,1,1,0}};
    // printf("Enter the adjacency matrix:\n");
    // for(i=0;i<n;i++)
    // {
    //     for(j=0;j<n;j++)
    //     {
    //         scanf("%d",&graph[i].distance);
    //         if(graph[i].distance==1)
    //             graph[j].parent=i;
    //     }
    // }
    bfs(adjMatrix,2);
    return 0;
}