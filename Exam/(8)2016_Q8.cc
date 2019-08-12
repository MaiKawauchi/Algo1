#include <iostream>
#include <algorithm>
#include <vector>

#define N 500000

int main ()
{
  std::vector <int> s;
  // Input
  for (int i = 0; i < N; ++i)
  {
    int temp;
    std::cin >> temp;
    s.push_back (temp);
  }

  while (s.size () != 3)  {
    // tiisaizyun
    std::sort (s.begin (), s.end ());
    int a = s.back ();
    s.pop_back ();
    int b = s.back ();
    s.pop_back ();
    s.push_back ((a + b) % 1000000000);
  }

  for (int i = 0; i < 3; ++i)
  {
    std::cout << s[i] << std::endl;
  }

  return 0;
}
