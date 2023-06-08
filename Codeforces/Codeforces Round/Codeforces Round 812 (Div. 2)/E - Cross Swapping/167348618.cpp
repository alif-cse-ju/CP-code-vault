#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define fi first
#define se second
#define pb push_back
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
using ll = long long;
using ii = pair<int,int>;
vector<int> p;
vector<int> col;
vector<vector<int>> st;
int find(int u) {
if (p[u] == u) return u;
return p[u] = find(p[u]);
void join(int u, int v, int ty) {
// cout << "@ " << u << "," << v << " by " << ty << "\n";
int U = u, V = v;
  u = find(u), v = find(v);
if (u == v) return;
if (sz(st[u]) < sz(st[v])) {
    swap(u, v);
    swap(U, V);
}
if (col[U] == -1 && col[V] == -1) {
    col[U] = ty;
    col[V] = ty ^ ty;
}
else if (col[U] == -1) {
    col[U] = col[V] ^ ty;
  } else if (col[V] == -1) {
    col[V] = col[U] ^ ty;
  }
  else if (col[U] ^ col[V] != ty) {
    for (int node : st[v])
      col[node] ^= 1;
  }
  for (int node : st[v]) st[u].pb(node);
  st[v].clear();
  p[v] = u;
}
 int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc; cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        cin >> a[i][j];
    }
        p.clear(); p.resize(n, 0); iota(all(p), 0);
    col.clear(); col.resize(n, -1);
    st.clear(); st.resize(n);
    for (int i = 0; i < n; ++i) st[i].pb(i);
        for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (a[i][j] == a[j][i]) continue;
        if (a[i][j] < a[j][i]) {
          join(i, j, 0);
        } else join(i, j, 1);
      }
    }
     auto apply = [&](int k) {
      for (int i = 0; i < n; ++i) 
        swap(a[i][k], a[k][i]);
    };
    for (int i = 0; i < n; ++i) if (col[i])
      apply(i);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        cout << a[i][j] << " ";
      cout << "\n";
    }
  }
  return 0;
}