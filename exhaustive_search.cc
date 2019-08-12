#include <iostream>

int n, A[50];

int main(){
  int q, i, M;

  std::cin >> n;
  for(int i=0; i<n; i++){ std::cin >> A[i]; }
  std::cin >> q;
  for(int i=0; i<q; i++){
    std::cin >> M;
    if( solve(0, M) ){
      std::cout << "yes";
    }else std::cout << "no";
  }
  return 0;
}

int solve(int i, int m){
  if( m==0 ){ return 1; }
  if( i>=n ){ return 0; }

  int res = solve(i+1, m) || solve(i+1, m-A[i]);
  return res;
}
