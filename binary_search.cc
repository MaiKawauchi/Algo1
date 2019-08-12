#include <iostream>

int n, S[100000];

int search(int T){
  int l=0, r=n;
  int mid;

  while( l < r ){
    mid = ( l+r )/2;
    if( T==S[mid] ) return 1;
    if( T>S[mid] ) l=mid+1;
    else if( T<S[mid] ) r=mid;
  }
  return 0;
}

int main(){
  int i, q;
  int T[50000];
  int count=0;

  std::cin >> n;
  for(int i=0; i<n; i++){
    std::cin >> S[i];
  }
  std::cin >> q;
  for(int i=0; i<q; i++){
    std::cin >> T[i];
    if(search(T[i])) { count++; }
  }
  std::cout << count << std::endl;
  return 0;
}
