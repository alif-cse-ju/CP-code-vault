#include <bits/stdc++.h>

using namespace std;

const int LG = 30;
const int N = 200010;

struct basis {
  int vec[LG];

  void clear() {
    memset(vec, 0, sizeof vec);
  }

  void insert (int x) {
    for (int i = LG - 1; i >= 0; --i) if (x & 1 << i) {
      if (vec[i]) x ^= vec[i];
      else {vec[i] = x; break;}
    }
  }

  int get() {
    int res = 0;
    for (int i = LG - 1; i >= 0; --i) res = max(res, res ^ vec[i]);
    return res;
  }
};

vector <int> g[N];
basis up[N], down[N], pref[N], suff[N];
int t, n, q, a[N], in[N], out[N], h[N], p[N], jump[N], ptr;

void merge (basis &A, basis &B) {
  for (int i = 0; i < LG; ++i) if (B.vec[i]) A.insert(B.vec[i]);
}

void dfsDown (int u = 1, int par = -1) {
  in[u] = ++ptr;
  for (int v : g[u]) if (v ^ par) {
    p[v] = u, h[v] = h[u] + 1;
    int x = jump[u], y = jump[x];
    jump[v] = (h[u] + h[y] == h[x] << 1) ? y : u;
    dfsDown(v, u);
    merge(down[u], down[v]);
  }
  down[u].insert(a[u]), out[u] = ptr;
}

void dfsUp (int u = 1, int par = -1) {
  vector <int> childs;
  for (int v : g[u]) if (v ^ par) childs.emplace_back(v);
  pref[0].clear();
  for (int i = 0; i < childs.size(); ++i) {
    int v = childs[i];
    pref[i + 1] = pref[i];
    merge(pref[i + 1], down[v]);
  }
  suff[childs.size()].clear();
  for (int i = (int) childs.size() - 1; i >= 0; --i) {
    int v = childs[i];
    suff[i] = suff[i + 1];
    merge(suff[i], down[v]);
  }
  for (int i = 0; i < childs.size(); ++i) {
    int v = childs[i]; 
    up[v] = up[u], up[v].insert(a[u]);
    merge(up[v], pref[i]); merge(up[v], suff[i + 1]);
  }
  for (int v : g[u]) if (v ^ par) dfsUp(v, u);
}

int findParent (int u, int k) {
  while (h[u] > k) u = h[jump[u]] < k ? p[u] : jump[u];
  return u;
}

int main() {
  clock_t st = clock();
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      g[i].clear(), up[i].clear(), down[i].clear();
    }
    for (int i = 1, u, v; i < n; ++i) {
      scanf("%d %d", &u, &v);
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    ptr = h[1] = 0, p[1] = -1, jump[1] = 1; 
    dfsDown(); dfsUp();
    scanf("%d", &q);
    while (q--) {
      int root, node;
      scanf("%d %d", &root, &node);
      if (root == node) {
        printf("%d\n", down[1].get());  
      } else if (in[node] <= in[root] and in[root] <= out[node]) {
        printf("%d\n", up[findParent(root, h[node] + 1)].get());
      } else {
        printf("%d\n", down[node].get());
      }
    }
  }
  return 0;
}

