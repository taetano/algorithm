#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int from, to;
int cnt[101];
int ret;

int main()
{
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> a >> b >> c;
  int i = 0;
  while (i++ < 3)
  {
    cin >> from >> to;
    for (int i = from; i < to; i++)
    {
      cnt[i]++;
    }
  }

  for (int n : cnt)
  {
    if (n == 1)
    {
      ret += a;
    }
    else if (n == 2)
    {
      ret += b * 2;
    }
    else if (n == 3)
    {
      ret += c * 3;
    }
  }

  cout << ret << "\n";
  return 0;
}