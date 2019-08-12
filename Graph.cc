#include <iostream>
#define N 110

int main(){
  int A[N][N];
  int n;
  std::cin >> n;

  for(int i=0; i<n; i++){
    int u, k;
    std::cin >> u >> k;
    int v;
    for(int j=0; j<k; j++){
      std::cin >> v;
      A[u][v]=1;
    }
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      std::cout << A[i][j];
      if( j!=n ){
      std::cout << " ";
      }
    }
    std::cout << std::endl;
  }

  return 0;
}
