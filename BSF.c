
#include <stdio.h>
#define N 6

int g[N][N] = {
    {0,1,1,0,0,0},
    {1,0,0,1,0,0},
    {1,0,0,1,1,0},
    {0,1,1,0,0,1},
    {0,0,1,0,0,1},
    {0,0,0,1,1,0}
};

int vis[N];

void bfs(int start){
    int q[N], front=0, rear=0;
    vis[start]=1; q[rear++]=start;
    while(front<rear){
        int u=q[front++];
        printf("%d ",u);
        for(int v=0;v<N;v++)
            if(g[u][v] && !vis[v]){
                vis[v]=1; q[rear++]=v;
            }
    }
}

int main(){
    printf("BFS starting from 0: ");
    bfs(0);
    return 0;
}
