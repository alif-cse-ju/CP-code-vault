#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt")
using ll = long long int;
using ull = unsigned long long int;
using vi = vector<ll>;
using ii = pair<int,int>;
using vii = vector<ii>;
using ld = long double;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree < T, null_type, less<T>,
rb_tree_tag,
tree_order_statistics_node_update >;
#ifdef SA_DEBUG
template <class T>
void print(T a) {cerr << a << endl;}
template <class T, class... V> 
void print(T a, V... b) {cerr << a << ", "; print(b...);}
#define dbg(...) cerr << "[" << __LINE__ << "] " << #__VA_ARGS__ << " :: ", print(__VA_ARGS__)
#else
#define dbg(...) 7
#endif
#define eb emplace_back
#define fi first
#define se second
const ll INFL = 2e18;
const int INF = 1e9;
//const double PI = acos(-1);
const ll mod = 998244353;
 mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 template<class T, class V> 
ostream& operator << (ostream &s, pair<T, V> a){
 s << a.fi << ' ' << a.se; return s;
}
 template<class T, class V> 
istream& operator >> (istream &s, pair<T, V> &a){
 s >> a.fi >> a.se; return s;
}
 template<class T> 
ostream& operator << (ostream &s, vector<T> a){
 for(int i = 0; i < (int)a.size(); i++){
  if(i > 0)s << ' ' ; 
  s << a[i];
 } return s;
}
 template<class T> 
istream& operator >> (istream &s, vector<T> &a){
 for(T &x : a)s >> x; 
 return s;
}
 template<class T> 
void input(T a[], int l, int r, istream &s = cin){
 while(l <= r)s >> a[l++];
}
 template<class T> 
void output(T a[], int l, int r, bool en = true, ostream &s = cout){
 while(l <= r){ s << a[l++];
  if(l <= r) s << ' ';
 } if(en)s << "\n";
}
   const int N = 3e5 + 1005, K = 1000, M = 10000;
//====================================================================//
namespace minSegTree{
 int st[N << 2];
 int f(int l,int r){
   return min(l, r);
 }
 void init(int node, int ss, int sf){
   if(ss == sf){
     st[node] = INF;
     return;
   }
   int mid = ss + sf >> 1;
   init(node << 1, ss, mid);
   init(node << 1 | 1, mid + 1, sf);
   st[node] = f(st[node << 1], st[node << 1 | 1]);
 }
 void update(int node, int ss, int sf, int pos, int val){
   if(ss == sf){
     st[node] = min(val, st[node]);
     return;
   }
   int mid = ss + sf >> 1;
   if(pos <= mid) update(node << 1, ss, mid, pos, val);
   else update(node << 1 | 1, mid + 1, sf, pos, val);
   st[node] = f(st[node << 1], st[node << 1 | 1]);
 }
 int query(int node, int ss, int sf, int qs, int qe){
   if(qs > sf || qe < ss || qe < qs)return INF;
   if(qs <= ss && qe >= sf)return st[node];
   int mid = ss + sf >> 1;
   return f(query(node << 1, ss, mid, qs, qe), query(node << 1 | 1, mid + 1, sf, qs, qe));
 }
}
namespace maxSegTree{
 int st[N << 2];
 int f(int l,int r){
   return max(l, r);
 }
 void init(int node, int ss, int sf){
   if(ss == sf){
     st[node] = -1;
     return;
   }
   int mid = ss + sf >> 1;
   init(node << 1, ss, mid);
   init(node << 1 | 1, mid + 1, sf);
   st[node] = f(st[node << 1], st[node << 1 | 1]);
 }
 void update(int node, int ss, int sf, int pos, int val){
   if(ss == sf){
     st[node] = val;
     return;
   }
   int mid = ss + sf >> 1;
   if(pos <= mid) update(node << 1, ss, mid, pos, val);
   else update(node << 1 | 1, mid + 1, sf, pos, val);
   st[node] = f(st[node << 1], st[node << 1 | 1]);
 }
 int query(int node, int ss, int sf, int qs, int qe){
   if(qs > sf || qe < ss || qe < qs)return -1;
   if(qs <= ss && qe >= sf)return st[node];
   int mid = ss + sf >> 1;
   return f(query(node << 1, ss, mid, qs, qe), query(node << 1 | 1, mid + 1, sf, qs, qe));
 }
}
 void solve(vector<int> &v, vector<tuple<int, int, int>> qr, vector<int> &ans){
 sort(qr.begin(), qr.end());
 int n = v.size(), q = qr.size();
 maxSegTree::init(1, 0, n - 1);
 minSegTree::init(1, 0, n - 1);
 for(int i = 0, e = 0; i < n; i++){
  int lo = 0;
  while(true){
   int idx = maxSegTree::query(1, 0, n - 1, lo, v[i]);
   if(idx == -1)break;
   int dif = v[i] - v[idx];
   assert(dif > 0);
   minSegTree::update(1, 0, n - 1, idx, dif);
   lo = v[i] - dif / 2;
  }
  maxSegTree::update(1, 0, n - 1, v[i], i);
  while(e < q && get<0>(qr[e]) == i){
   auto [r, l, idx] = qr[e++];
   ans[idx] = min(ans[idx], minSegTree::query(1, 0, n - 1, l, r - 1));
  }
 }
}
 void testcase(){
 int n, q;
 cin >> n >> q;
 vector<int> v(n);
 for(auto &x : v)cin >> x, x--;
 vector<tuple<int, int, int>> qr;
 for(int i = 0; i < q; i++){
  int l, r;
  cin >> l >> r;
  l--, r--;
  qr.eb(r, l, i);
 }
  vector<int> ans(q, INF);
 solve(v, qr, ans);
 for(auto &[r, l, i] : qr){
  r = n - 1 - r;
  l = n - 1 - l;
  swap(l, r);
 }
 reverse(v.begin(), v.end());
 solve(v, qr, ans);
  for(auto x : ans)cout << x << "\n";
  return;
}
     int main(){
 ios::sync_with_stdio(false);
 cin.tie(NULL);
  int T = 1;
 //cin >> T;
  for(int qq = 1; qq <= T; ++qq){
  //cout << "Case #" << qq << ": ";
  testcase();
 }
 return 0;
}
/*
1
13 5
*/