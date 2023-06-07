#include<bits/stdc++.h>
using namespace std;

using ll = long long;
vector<int> divs(int n) {
  vector<int> v;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      v.push_back(i);
      if (i != n / i) {
        v.push_back(n / i);
      }
    }
  }
  return v;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m1, m2; cin >> n >> m1 >> m2;
    auto d1 = divs(m1);
    auto d2 = divs(m2);
    set<ll> se;
    for (auto x: d1) {
      for (auto y: d2) {
        se.insert(1LL * x * y);
      }
    }
    vector<ll> d(se.begin(), se.end());
    int sz = d.size();
    int cnt = 0, xr = 0;
    for (int i = 0; i < sz; i++) {
      ll x = d[i];
      int l = 1, r = sqrtl(x) + 5, k = 1;
      while (1LL * r * r > x) --r;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (max((ll)mid, x / mid) <= n) {
          k = mid;
          r = mid - 1;
        }
        else {
          l = mid + 1;
        }
      }
      int j = lower_bound(d.begin(), d.begin() + i + 1, (ll)k) - d.begin();
      while (j < sz and x % d[j] != 0) ++j;
      if (j < sz and max(d[j], x / d[j]) <= n) {
        ++cnt;
        xr ^= d[j];
      }
    }
    cout << cnt << ' ' << xr << '\n';
  }
  return 0;
}