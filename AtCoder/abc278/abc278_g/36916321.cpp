#include "bits/stdc++.h"
using namespace std;
#define int long long
const int MAXN = 3e5 + 10;
const int MOD = 1e9 + 7;
mt19937_64 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) {
  int u = uniform_int_distribution<int>(x, y)(rng); return u;
}
int bm(int b, int p) {
  if(p==0) return 1 % MOD;
  int r = bm(b, p >> 1);
  if(p&1) return (((r*r) % MOD) * b) % MOD;
  return (r*r) % MOD;
}
int inv(int b) { 
  return bm(b, MOD-2);
}
int fac[MAXN];
int nCr(int n, int r) { 
  int ans = fac[n]; ans *= inv(fac[r]); ans %= MOD;
  ans *= inv(fac[n-r]); ans %= MOD; return ans;
}
void precomp() { 
  for(int i=0; i<MAXN; i++) fac[i] = (i == 0 ? 1 % MOD : (fac[i-1] * i) % MOD); 
}
int fastlog(int x) {
  return (x == 0 ? -1 : 64 - __builtin_clzll(x) - 1);
}
void printcase(int i) { cout << "Case #" << i << ": "; }
void solve(int tc) {
  int n, l, r;
  cin >> n >> l >> r;
  int sg[n+1];
  for(int i=0; i<l; i++) sg[i] = 0;
  vector<pair<int, int> > sum[2*n + 1]; 
  sum[0].push_back({0, 0});
  for(int i=1; i<l; i++) {
    for(int j=0; j<=i/2; j++) {
      sum[sg[j] ^ sg[i-j]].push_back({i, j});
    }
  }
  for(int i=l; i<=n; i++) {
    int cur = 0;
    while(1) {
      if(sum[cur].empty()) break;
      pair<int, int> wow = *lower_bound(sum[cur].begin(), sum[cur].end(), make_pair(i-r, 0ll));
      if(i-r <= wow.first && wow.first <= i-l) {
        cur++;
      }
      else {
        break;
      }
    }

    sg[i] = cur;

    for(int j=0; j<=i/2; j++) {
      sum[sg[j] ^ sg[i-j]].push_back({i, j});
    }
  }

  //for(int i=0; i<=n; i++) cout <<sg[i] << " \n"[i == n];
  vector<pair<int, int> > ranges;
  if(sg[n] == 0) {
    // losing state
    cout << "Second" << endl;
    int a, b;
    cin >> a >> b;
    if(a == 0 && b == 0) {
      return;
    }
    if(a > 1) ranges.push_back({1, a-1});
    if(a+b <= n) ranges.push_back({a+b, n});
  }
  else {
    cout << "First" << endl;
    ranges.push_back({1, n});
  }
  
  while(1) {
    // find a state with xor of grundy values = 0
    int xsum = 0;
    for(pair<int, int> x: ranges) xsum ^= (sg[x.second - x.first + 1]);
    assert(xsum > 0);
    for(pair<int, int> z: ranges) {
      int len = z.second - z.first + 1;
      xsum ^= sg[len];
      pair<int, int> val = *lower_bound(sum[xsum].begin(), sum[xsum].end(), make_pair(len - r, 0ll));
      if(val.first >= len - r && val.first <= len - l && (sg[val.second] ^ sg[val.first - val.second]) == xsum) {
        int y = len - val.first;
        int x = val.second + z.first;
        cout << x << ' ' << y << endl;
        for(int i=0; i<ranges.size(); i++) {
          if(ranges[i] == z) {
            ranges.erase(ranges.begin() + i); break;
          }
        }
        if(val.second > 0) ranges.push_back({z.first, z.first + val.second - 1});
        if(x + y <= z.second) ranges.push_back({x + y, z.second});
        break;
      }
      xsum ^= sg[len];
    }

    sort(ranges.begin(), ranges.end());
    int a, b;
    cin >> a >> b;

    if(a == 0 && b == 0) return;
    for(pair<int, int> z: ranges) {
      if(z.first <= a && a <= z.second) {
        for(int i=0; i<ranges.size(); i++) {
          if(ranges[i] == z) {
            ranges.erase(ranges.begin() + i); break;
          }
        }
        if(z.first < a) ranges.push_back({z.first, a-1});
        if(a+b <= z.second) ranges.push_back({a+b, z.second});
        break;
      }
    }
    
    sort(ranges.begin(), ranges.end());
  }
  
}
int32_t main() {
  precomp();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; //cin >> t;
  for(int i=1; i<=t; i++) solve(i);
}