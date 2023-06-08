#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using vi = vector<ll>;
using ii = pair<ll,ll>;
using iii = pair<ii,ll>;
using vii = vector<ii>;
using ld = long double;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef
tree < ll, null_type, less<ll>,
rb_tree_tag,
tree_order_statistics_node_update > ordered_set;
template <class T>
void print(T a) {cerr << a << endl;}
template <class T, class... V>
void print(T a, V... b) {cerr << a << ", "; print(b...);}
#define dbg(...) cerr << "[" << __LINE__ << "] " << #__VA_ARGS__ << " :: ", print(__VA_ARGS__)
#define getbit(n, i) (((n) >> (i)) & 1)
#define lastone(n) ((n) & (-(n)))
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
const ll INFL = 2e18;
const int INF = 1e9;
const double PI = acos(-1);
const ll mod = 1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T, class V>
ostream& operator << (ostream &s, pair<T, V> a){
    s << a.fi << ' ' << a.se;
    return s;
}
 const int N = 1e4 + 3, K = 6;
 int dis[N][1 << K];
vector<int> adj[N];
int fr[N];
int p[N];
int indx[N];
int indx2[N];
int dp[2][1 << K];
  int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
     int T = 1;
    cin >> T;
    for(int qq = 1; qq <= T; qq++){
  int k, n, m, f;
  cin >> n >> m;
  for(int i = 1; i <= n; i++)adj[i].clear(), indx[i] = 0;
  for(int i = 0; i < m; i++){
   int u, v;
   cin >> u >> v;
   adj[u].eb(v);
   adj[v].eb(u);
  }
    cin >> f;
  for(int i = 0; i < f; i++)cin >> fr[i], indx2[i] = 0;
    cin >> k;
  //dbg(k);
  for(int i = 0; i < k; i++)cin >> p[i], indx[fr[--p[i]]] |= (1 << i), indx2[p[i]] = 1;
    for(int i = 1; i <= n; i++){
   for(int j = 0; j < (1 << k); j++)dis[i][j] = INF;
  }
    queue<pair<int, int>> q;
    q.emplace(1, 0);
  dis[1][0] = 0;
    while(!q.empty()){
   auto [u, msk] = q.front();
   q.pop();
   int d = dis[u][msk];
   for(auto x : adj[u]){
    for(int j = indx[x]; j >= 0; j = (j - 1) & indx[x]){
     int t = msk | j;
     if(dis[x][t] == INF){
      dis[x][t] = d + 1;
      q.emplace(x, t);
     }
     if(j == 0)break;
    }
   }
  }
    memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
    int a = 0, b = 1;
  for(int q = 0; q < f; q++){
   if(indx2[q])continue;
   int i = fr[q];
   //dbg(i);
   int mn = INF;
   for(int j = 0; j < (1 << k); j++)mn = min(mn, dis[i][j]);
      for(int j = 0; j < (1 << k); j++){
    dp[b][j] = dp[a][j];
    for(int l = j; l >= 0; l = (l - 1) & j){
     dp[b][j] = dp[b][j] | (dp[a][l] & (dis[i][j ^ l] == mn));
     if(l == 0)break;
    }
   }
   swap(a, b);
  }
    int ans = 0;
  for(int i = 0; i < (1 << k); i++){
   if(dp[a][i])ans = max(ans, __builtin_popcount(i));
  }
    //dbg(k);
  cout << k - ans << "\n";
    }
}
 /*
*/