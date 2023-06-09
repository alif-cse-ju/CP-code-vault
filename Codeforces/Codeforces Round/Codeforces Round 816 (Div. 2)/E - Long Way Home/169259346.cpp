#include <bits/stdc++.h>
using namespace std;
//#pragma GCC target ("avx2")
//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("unroll-loops")
// #include<bits/extc++.h>
// using namespace __gnu_pbds;
// template<typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template<typename T>
// using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define ook order_of_key
// #define fbo find_by_order
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " = " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " = " << arg1<<endl;
        __f(comma+1, args...);
    }
#define wait(x) this_thread::sleep_for(chrono::milliseconds(x))
#define seed 127
#else
#define trace(...) 42
#define seed chrono::steady_clock::now().time_since_epoch().count()
#define wait(x) 137
#endif
#define makegraph(adj, num)       \
    for (int i = 0; i < num; i++) \
    {                             \
        int u, v;                 \
        cin >> u >> v;            \
        adj[u].push_back(v);      \
        adj[v].push_back(u);      \
    }
#define rep(i, k, n) for (int i = k; i < n; i++)
#define rept(i, k, n) for (auto i = k; i != n; ++i)
#define drep(i, k, n) for (int i = k; i >= n; i--)
#define repeat(n) for(int _=0;_<n;_++)
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define all(a) a.begin(), a.end()
#define endl '\n'
#define ld long double
#define int long long
#define clr(s) memset(s, 0, sizeof(s))
#define valset(arr, size, val) rep(i, 0, size) arr[i] = val;
#define newint(...) int __VA_ARGS__;read(__VA_ARGS__);
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)
#define Tj return
#define out 0
// #define segtree
#ifdef segtree
#define mid (st + en) / 2
#define lidx 2 * ind + 1
#define ridx 2 * ind + 2
#define left st, mid, lidx, seg
#define right mid + 1, en, ridx, seg
#endif
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int>> iii;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef set<int> si;
typedef vector<vector<int>> vvi;
typedef __int128_t xll;
const int intmax = 2147483647;
const int intmin = -2147483648;
const int mod = 1000000007;
const int mod2 = 998244353;
mt19937 rng(seed);
 //IO operators for vectors, pairs, sets, maps and __int128
template <typename T>istream &operator>>(istream &in, vector<T> &v){for (auto &i : v)in >> i;return in;}
template <typename T>ostream &operator<<(ostream &ost, vector<T> v){if(&ost == &cerr){cerr <<"{";int cnt = v.size();for(auto x:v){cerr << x;cnt--;if(cnt) cerr << ", ";}cerr << "}";}else for(auto i:v)ost << i << " ";return ost;}
template <typename T>ostream &operator<<(ostream &ost, set<T> s){if(&ost == &cerr){cerr <<"{";int cnt = s.size();for(auto x:s){cerr << x;cnt--;if(cnt) cerr << ", ";}cerr << "}";}else for(auto i:s)ost << i << " ";return ost;}
template <typename T>ostream &operator<<(ostream &ost, multiset<T> s){if(&ost == &cerr){cerr <<"{";int cnt = s.size();for(auto x:s){cerr << x;cnt--;if(cnt) cerr << ", ";}cerr << "}";}else for(auto i:s)ost << i << " ";return ost;}
template <typename U, typename V>ostream &operator<<(ostream &ost, map<U,V> &m){if(&ost == &cerr){cerr <<"{";int cnt = m.size();for(auto x:m){cerr << x; cnt--;if(cnt) cerr << ", ";}cerr << "}";}else for(auto i:m)ost << i;return ost;}
template <typename U, typename V>istream &operator>>(istream &in, pair<U, V> &p){in>>p.first>>p.second;return in;}
template <typename U, typename V>ostream &operator<<(ostream &ost, pair<U, V> p){if (&ost == &cerr)ost << "{" << p.first << ": " << p.second << "}";else ost << p.first << " " << p.second << " ";return ost;}
ostream &operator<<(ostream &ost, __int128_t x){string output = "";while(x)output += '0'+x%10, x /= 10;reverse(all(output)); ost << output;  return ost;}
istream &operator>>(istream &in, __int128_t &x){x=0;string num;cin >> num;for(char c:num) x *= 10, x += c-'0';return in;}
//Variadic IO
template <typename... T>void read(T &...args){((cin >> args), ...);}
template <typename... T>void print(T... args){((cout << args << " "), ...);cout << endl;}
 vi dp_old, dp_new;
 int C(int a, int b) {
    return (a-b)*(a-b);
}
 void compute(int l, int r, int optl, int optr, vi &dp_old) {
    if (l > r)
        return;
     int mid = (l + r) >> 1;
    pair<long long, int> best = {LLONG_MAX, -1};
     for (int k = optl; k <= min(mid, optr); k++) {
        best = min(best, mp(dp_old[k] + C(k, mid), k));
    }
     dp_new[mid] = best.first;
    int opt = best.second;
     compute(l, mid - 1, optl, opt, dp_old);
    compute(mid + 1, r, opt, optr, dp_old);
}
 void dijkstra(int n, vi &dp_old, vii *adj)
{
    priority_queue<ii,vii, greater<ii>> pq;
    rep(i,0,n) {
        pq.push({dp_old[i],i});
    }
    while (!pq.empty())
    {
        auto[dis,node] = pq.top();
        pq.pop();
        if(dis > dp_old[node]) continue;
        for(auto [child,weight]:adj[node]) {
            if(dp_old[child] > dis+weight) {
                dp_old[child] = dis+weight;
                pq.push({dis+weight,child});
            }
        }
    }
}
 void solve()
{
    newint(n,m,k);
    vii adj[n+1];
    rep(i,0,m) {
        newint(u,v,w);
        u--,v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<ii,vii, greater<ii>> pq;
    dp_old.resize(n, LONG_LONG_MAX/3);dp_new.resize(n);
    dp_old[0] = 0;
    pq.push({0,0});
    while (!pq.empty())
    {
        auto[dis,node] = pq.top();
        // trace(dis,node);
        pq.pop();
        if(dis > dp_old[node]) continue;
        for(auto [child,weight]:adj[node]) {
            if(dp_old[child] > dis+weight) {
                dp_old[child] = dis+weight;
                pq.push({dis+weight,child});
            }
        }
    }
    trace(dp_old);
    for (int i = 1; i <= k; i++) {
        auto dp_old_rev = dp_old;
        vi mn = dp_old;
        reverse(all(dp_old_rev));
        dp_new.assign(n,LONG_LONG_MAX/2);
        compute(0, n - 1, 0, n - 1, dp_old);
        trace(dp_new);
        rep(i,0,n) mn[i] = min(mn[i], dp_new[i]);
        dp_new.assign(n,LONG_LONG_MAX/2);
        compute(0, n - 1, 0, n - 1, dp_old_rev);
        reverse(all(dp_new));
        rep(i,0,n) mn[i] = min(mn[i], dp_new[i]);
        dp_old = mn;
        dijkstra(n,dp_old,adj);
    }
    cout << dp_old << endl;
}
 signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin >> t;
    rep(var,1,t+1)
        // cout << "Case #" << var << ": ",
        solve();
    Tj out;
}