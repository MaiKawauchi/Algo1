#include <iostream>
#include <limits>
#define N 110

int main(){
  int n;
  std::cin >> n;

  int A[N][N];
  int d[N] = {};
  int p[N];
  for(int i=0; i<n; i++){
    d[i] = std::numeric_limits<int>::max();
    p[i] = -1;
    for(int j=0; j<n; j++){
      std::cin >> A[i][j];
      if( A[i][j] == -1){ //no line
        A[i][j] = std::numeric_limits<int>::max();
      }
    }
  }
  d[0] = 0;

  int used[N] = {};
  while(1){
    int u;
    int min = std::numeric_limits<int>::max();
    for(int i=0; i<n; i++){
      if( used[i] != -1 && d[i]<min ){
        min = d[i];
        u = i;
      }
    }
    if(min==std::numeric_limits<int>::max()) break;
    used[u] = -1;

    for(int i=0; i<n; i++){
      if( used[i] != -1 && A[u][i] < d[i]){
        p[i] = u;
        d[i] = A[u][i];
        used[i] = 1;
      }
    }
  }
  int MST=0;
  for(int i=0; i<n; i++){
    if(p[i] != -1) MST += A[i][p[i]];
      }

  std::cout << MST << std::endl;

  return 0;
}
