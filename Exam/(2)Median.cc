#include <iostream>
#include <algorithm>
#include <vector>

#define N 101

int main(){
  int median;
  int n;
  std::vector<int> str;

  for(int i=0; i<N; i++){
    std::cin >> n;
    str.push_back(n);
  }
  std::sort(str.begin (), str.end ());

  // for(int i=0; i<N; i++){  std::cout << str[i] << std::endl; }

  median = str[50];

  std::cout << median << std::endl;

  return 0;
}
