#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

int main(){
  std::stack<int>S1;
  std::stack<std::pair<int, int> >S2;
  char ch;
  int sum = 0;
  for (int i = 0; std::cin >> ch; i++){
    if (ch == '\\') S1.push(i);
    else if (ch == '/' && S1.size() > 0){
      int j = S1.top();
      S1.pop();
      sum += i - j;
      int a = i - j;
      while (S2.size() > 0 && S2.top().first > j){
        a += S2.top().second;
        S2.pop();
      }
      S2.push(std::make_pair(j, a));
    }
  }

  std::vector<int>ans;
  int t = 0;
  while (S2.size() > 0){
    ans.push_back(S2.top().second);
    S2.pop();
  }
  reverse(ans.begin(), ans.end());
  std::cout << sum << "\n";
  std::cout << ans.size();
  for (int i = 0; i < ans.size(); i++){
    std::cout << " ";
    t += ans[i];
    std::cout << ans[i];
  }std::cout << "\n";

  return 0;
}
