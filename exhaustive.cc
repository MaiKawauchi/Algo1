#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> coin = {3, 6, 11, 28, 57, 86, 119};
std::vector<int> pay = {229, 111, 128, 71, 328, 255, 239, 260,
                        151, 163, 246, 184, 253, 97, 78, 114};

int solve(int i, int m){
  if( m==0 ) return 1;
  if( i>=coin.size() ) return 0;
  int res = solve( i+1, m ) || solve( i+1, m-coin[i] );
  return res;
}

int main(){
  
  std::sort(pay.begin(), pay.end());

  std::vector<int> ans;
  for(int i=0; i<pay.size(); i++){
    if( solve(0, pay[i]) ){ std::cout << "yes" << std::endl; }
    else { ans.push_back(pay[i]); }
  }
  for(int i=0; i<ans.size(); i++){
    std::cout << ans[i] << std::endl;
  }

  return 0;
}
