#include <iostream>
#include <queue>
#define N 110

int color[N];

int t = 1;

int d[N];
int A[N][N];
std::queue<int> q;
void Breadth(int id, int n){


  d[id] = t;
  t++;

  for(int i=1; i<=n; i++){
    if(A[id][i] == 1 && d[i] == 0){
      Breadth(i, n);
    }
  }
}

int main(){
  for(int i=0; i<N; i++){
    d[i]=0;
    for(int j=0; j<N; j++){
      A[i][j]=0;
    }
  }
  int n;
  std::cin >> n;
  for(int i=0; i<n; i++){
    int u, k, v;
    std::cin >> u >> k;
    for(int i=0; i<k; i++){
      std::cin >> v;
      A[u][v]=1;
    }
  }
  for(int i=1; i<=n; i++){
    if(d[i] == 0){ Breadth(i, n); }
  }
  for(int i=1; i<=n; i++){
    std::cout << i << " " << d[i]  << std::endl;
  }

  return 0;
}
