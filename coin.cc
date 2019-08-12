#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 500

int main ()
{
  std::vector <int> m = {3, 6, 11, 28, 57, 86, 119};
  std::vector <int> p = {299, 111, 128, 71, 328, 255, 239, 260, 151, 163, 246,
                         184, 253, 97, 78, 114};

  bool ans[MAX] = {false};
  for (int i = 0; i < m.size (); ++i) { ans[m[i]] = true; }

  for (int i = 0; i < MAX; ++i)
  {
    if (ans[i])
    {
      for (int j = 0; j < m.size (); ++j)
      {
        if (i < m[j] && i + m[j] < MAX)
        {
          ans[i + m[j]] = true;
        }
      }
    }
  }

  std::sort (p.begin (), p.end ());
  for (int i = 0; i < p.size (); ++i)
  {
    if (!ans[p[i]]) { std::cout << p[i] << std::endl; }
  }

  return 0;
}
