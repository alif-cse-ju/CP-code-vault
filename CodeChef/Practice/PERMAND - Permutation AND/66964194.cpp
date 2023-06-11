#include <bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
 void mainSolve()
{
  int n;
  cin >> n;
  if (n == 1)
  {
    cout << "1\n1\n";
    return;
  }
  if (n % 2 == 1)
  {
    cout << "-1\n";
    return;
  }
  ll p = 1;
  while (p <= n)
    p *= 2ll;
  vector<pair<ll, ll>> v;
  vector<bool> mark(n + 1, false);
  for (int i = n; i >= 1; i--)
  {
    if (mark[i])
      continue;
    while (2 * i < p)
      p /= 2;
    mark[i] = 1;
    mark[p - 1 - i] = 1;
    v.push_back({i, p - 1 - i});
  }
  for (auto it : v)
    cout << it.first << ' ';
  for (auto it : v)
    cout << it.second << ' ';
  cout << '\n';
  for (auto it : v)
    cout << it.second << ' ';
  for (auto it : v)
    cout << it.first << ' ';
  cout << '\n';
}
 int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--)
  {
    mainSolve();
  }
  return 0;
}