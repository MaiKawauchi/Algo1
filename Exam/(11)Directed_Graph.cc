#include <iostream>
#include <algorithm>
#define N 100
#define INF 1000000;

int main(){
  int A[N][N];

  //Initialization
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if( i==j ){ A[i][i] =0; }
      else A[i][j] = INF;
    }
  }

  //Input
  int u, k, v;
  for(int i=0; i<N; i++){
    std::cin >> u >> k;
    for(int j=0; j<k; j++){
      std::cin >> v;
      A[u - 1][v - 1] = 1;
    }
  }

  for(int k=0; k<N; k++){
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        A[i][j] = std::min( A[i][j], A[i][k]+A[k][j] );
      }
    }
  }

  for(int i=0; i<N; i++){
    std::cout << i+1 << " " << A[0][i] << std::endl;
  }
  return 0;
}
