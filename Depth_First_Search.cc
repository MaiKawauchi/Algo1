#include <iostream>
#define N 110

int t = 1;

int d[N], f[N];
int A[N][N];

void Depth(int id, int n){
  d[id] = t;
  t++;
  for(int i=1; i<=n; i++){
    if(A[id][i] == 1 && d[i] == 0){
      Depth(i, n);
    }
  }
  f[id] = t;
  t++;
}



int main(){
  for(int i=0; i<N; i++){
    d[i]=f[i]=0;
    for(int j=0; j<N; j++){
      A[i][j]=0;
    }
  }
  //Input
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
    if(d[i] == 0 && f[i] == 0){ Depth(i, n); }
  }
  for(int i=1; i<=n; i++){
    std::cout << i << " " << d[i] << " " << f[i] << std::endl;
  }

  return 0;
}
