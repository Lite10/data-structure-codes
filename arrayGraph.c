
#include <stdio.h>
#define N 7

int g[N][N] = {
    {0,1,0,0,0,0,0},
    {1,0,1,0,0,0,0},
    {0,1,0,0,0,0,0},
    {0,0,0,0,1,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,0,0,0,1},
    {0,0,0,0,0,1,0}
};
int vis[N];

void dfs(int u){
    vis[u]=1; printf("%d ",u);
    for(int v=0;v<N;v++) if(g[u][v] && !vis[v]) dfs(v);
}

int main(){
    for(int i=0;i<N;i++) if(!vis[i]){
        printf("{ "); dfs(i); printf("}\n");
    }
    return 0;
}
