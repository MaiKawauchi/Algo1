#include <iostream>

int search(int S[], int n, int T){
  int i=0;
  S[n] = T;
  while(S[i] != T){ i++; }
  return i != n;
}

int main(){
  int S[10000], T[500];
  int i, n, q;
  int count=0;

  std::cin >> n;
  for(int i=0; i<n; i++){
    std::cin >> S[i];
  }
  std::cin >> q;
  for(int i=0; i<q; i++){
    std::cin >> T[i];
    if(search(S, n, T[i])) {count++;}
  }

  std::cout << count << std::endl;
  return 0;
}
