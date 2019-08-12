#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define N 500000

int main ()
{
  std::map <int, int> a;

  // Input
  for (int i = 0; i < N; ++i)
  {
    int tmp;
    std::cin >> tmp;
    a.insert (std::make_pair (tmp, tmp));
  }

  std::vector <int> ans;
  for (int i = 0; i < N; ++i)
  {
    int tmp;
    std::cin >> tmp;
    auto result = a.insert (std::make_pair (tmp, tmp));
    if (!result.second)
    {
      ans.push_back (tmp);
    }
  }

  std::sort (ans.begin (), ans.end ());
  for (const auto &t : ans)
  {
    std::cout << t << std::endl;
  }
}
