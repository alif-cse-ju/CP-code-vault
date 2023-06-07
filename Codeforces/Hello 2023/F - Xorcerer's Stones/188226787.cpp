#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> p(n);
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    --p[i];
  }
  vector<int> x = a;
  vector<int> sz(n, 1);
  for (int i = n - 1; i > 0; i--) {
    x[p[i]] ^= x[i];
    sz[p[i]] += sz[i];
  }
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    g[p[i]].push_back(i);
  }
  vector<vector<bool>> dp(n, vector<bool>(32, false));
  for (int i = n - 1; i >= 0; i--) {
    dp[i][0] = true;
    for (int u : g[i]) {
      vector<bool> new_dp(32, false);
      for (int x = 0; x < 32; x++) {
        if (dp[i][x]) {
          for (int y = 0; y < 32; y++) {
            if (dp[u][y]) {
              new_dp[x ^ y] = true;
            }
          }
        }
      }
      swap(dp[i], new_dp);
    }
    if (sz[i] % 2 == 0) {
      dp[i][x[i]] = true;
    }
  }
  if (!dp[0][x[0]]) {
    cout << -1 << '\n';
    return 0;
  }
  vector<int> tyk;
  function<void(int, int)> Restore = [&](int v, int val) {
    if (val == 0) {
      return;
    }
    if (sz[v] % 2 == 0 && val == x[v]) {
      tyk.push_back(v);
      return;
    }
    int sz = (int) g[v].size();
    vector<vector<int>> pr(sz + 1, vector<int>(32, -1));
    pr[0][0] = 0;
    for (int it = 0; it < sz; it++) {
      int i = g[v][it];
      for (int j = 0; j < 32; j++) {
        for (int k = 0; k < 32; k++) {
          if (pr[it][j] != -1 && dp[i][k]) {
            pr[it + 1][j ^ k] = k;
          }
        }
      }
    }
    assert(pr[sz][val] != -1);
    vector<int> use(sz);
    int cur = val;
    for (int it = sz; it > 0; it--) {
      use[it - 1] = pr[it][cur];
      cur ^= pr[it][cur];
    }
    for (int it = 0; it < sz; it++) {
      int i = g[v][it];
      Restore(i, use[it]);
    }
  };
  Restore(0, x[0]);
  tyk.push_back(0);
  cout << tyk.size() << '\n';
  for (int i = 0; i < (int) tyk.size(); i++) {
    cout << tyk[i] + 1 << " \n"[i == (int) tyk.size() - 1];
  }
  return 0;
}
