#include <iostream>
#include <stdio.h>
#include <queue>
 
using namespace std;
#define N 100
#define INF 2000000
 
int n, M[N][N];
int d[N];
 
void bfs(int s){
    int i,u,v;
 
    queue<int> q;
    q.push(s);
    for(i = 0; i < n; i++){
        d[i] = INF;
    }
 
    d[s] = 0;
 
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(v = 0; v < n; v++){
            if(M[u][v] == 0) continue;
            if(d[v] != INF) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    for(i = 0; i < n; i++){
        if(d[i] == INF){
            printf("%d -1\n", i+1);
        }else{
            printf("%d %d\n", i+1, d[i]);
        }
    }
}
 
 
int main(void){
    int i,j,u,k,v;
 
    scanf("%d", &n);
 
    for(i = 0;i < n; i++){
        for(j = 0; j < n; j++){
            M[i][j] = 0;
        }
    }
 
    for(i = 0; i < n; i++){
      cin >> u >> k;
        u--;
        for(j=0;j<k;j++){
          cin >> v;
            v--;
            M[u][v] = 1;
        }
    }
 
    bfs(0);
 
    return 0;
}
