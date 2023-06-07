#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7, mod = 998244353;

int n, k, a[sz], b[sz], dep[sz];
ll has[sz], csub[sz];
vector <int> g[sz];

ll bigmod(ll b, ll n) {
   b %= mod;
   if(n == -1) n = mod - 2;
   ll ans = 1;
   while(n) {
      if(n & 1) ans = ans * b % mod;
      n >>= 1;
      b = b * b % mod;
   }
   return ans;
}

const ll two = bigmod(2, -1);

void dfs(int u, int p) {
   csub[u] = has[u];
   for(int v : g[u]) if(v != p) {
      dep[v] = dep[u] + 1;
      dfs(v, u);
      csub[u] += csub[v];
   }
}

int main() {
   cin >> n >> k;
   for(int i=0, u; i<k; i++) {
      scanf("%d", &u);
      has[u] = 1;
   }
   for(int i=1; i<n; i++) {
      scanf("%d %d", &a[i], &b[i]);
      g[a[i]].push_back(b[i]);
      g[b[i]].push_back(a[i]);
   }
   dfs(1, 0);


   ll ans = 0;
   for(int i=1; i<n; i++) {
      int u = a[i], v = b[i];
      if(dep[u] > dep[v]) swap(u, v);
      // u parent of v
      ll cv = csub[v], cu = k - cv;

      // initial
      ans += cu * cv;

      ll hsu = 0, hsv = 0;

      // u goes to v
      {
         ll prob = has[u] * (1 - has[v]) % mod;
         prob = prob * two % mod;
         ans += (cu - cv - 1) * prob % mod;
         ans %= mod;

         hsv += prob;
      }

      // v goes to u
      {
         ll prob = has[v] * (1 - has[u]) % mod;
         prob = prob * two % mod;
         ans += (cv - cu - 1) * prob % mod;
         ans %= mod;

         hsu += prob;
      }

      ll both = has[u] * has[v] % mod;
      
      // stay at u
      {
         ll stay = (has[u] + both) % mod;
         stay = stay * two % mod;
         has[u] = (stay + hsu) % mod;
      }

      // stay at v
      {
         ll stay = (has[v] + both) % mod;
         stay = stay * two % mod;
         has[v] = (stay + hsv) % mod;
      }
   }

   ll ways = k * (k - 1LL) / 2;
   ans = ans * bigmod(ways, -1) % mod;
   if(ans < 0) ans += mod;
   cout << ans;
}
