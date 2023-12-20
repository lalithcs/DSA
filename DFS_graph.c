#include<stdio.h>
#include<conio.h>
void dfs(int);
int n,a[10][10];
int visited[10];
void main()
{
    int i,j,v;
    printf("Enter the no. of nodes in the Graph:\t");
    scanf("%d",&n);
    printf("Enter the adjacency matrix: \n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    printf("Enter the starting node for Depth First search:\t");
    scanf("%d",&v);
    for(i=0;i<n;i++)
    visited[i]=0;
    dfs(v);
    getch();
}
void dfs(int v)
{
    int i,stack[10],top=-1,popped;
    stack[++top]=v;
    while(top>=0)
    {
        popped=stack[top--];
        if(visited[popped]==0)
        {
        printf("->%c",popped+65);
        visited[popped]=1;
        }
        for(i=n-1;i>=0;i--)
            if(a[popped][i]==1 && visited[i]==0)
        stack[++top]=i;
    }
}