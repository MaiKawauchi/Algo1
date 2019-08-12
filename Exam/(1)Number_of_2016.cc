#include <iostream>
#include <algorithm>
#include <string>
#define N 10000

int main(){
  int str[N];
  int count =0;
  for(int i=0; i<N; i++){
    std::cin >> str[i];
    if( str[i] == 2016 ){ count++; }
  }

  std::cout << count << std::endl;
  return 0;
}

