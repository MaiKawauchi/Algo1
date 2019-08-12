#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> num;

int main(){
  int temp;
  
  for(int i=0; i<1000000; i++){
   std::cin >> temp;
   num.push_back(temp);
  }
  std::sort(num.begin(), num.end());

  std::cout << num[99] << std::endl;


  return 0;
}
