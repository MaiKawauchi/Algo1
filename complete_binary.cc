#include <iostream>

int main(){
  int h;
  int key[251];
  std::cin >> h;
  for(int i=0; i<h; i++){ std::cin >> key[i]; }

  for(int i=0; i<h; i++){
    std::cout << "node " << i+1 << ": ";
    std::cout << "key = " << key[i] << ", ";
    if( i>0 ){ std::cout << "parent key = " << key[(i-1)/2] << ", "; }
    if( i*2+1<h ){ std::cout << "left key = " << key[2*i+1] << ", "; }
    if( i*2+2<h ){ std::cout << "right key = " << key[2*i+2] << ", "; }
    std::cout << std::endl;
  }
  return 0;
}
