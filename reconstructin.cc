#include <iostream>

using namespace std;

int preO[40], inO[40], posO[40];

void solve(int left, int right){
  int m;
  if(left > right) return;
  int x = preO[m++];

  solve(left, posO[x]-1);
  solve(posO[x]+1, right);

  std::cout << x;
}


int main(){
  int n;
  std::cin >> n;

  for(int i=0; i<n; i++) std::cin >> preO[i];
  for(int i=0; i<n; i++) std::cin >> inO[i], posO[inO[i]] = i;

  solve(0, n-1);

  return 0;
}
