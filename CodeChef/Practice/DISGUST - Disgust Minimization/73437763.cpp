#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define int long long
using namespace std;
const int N = 5e3 + 5, MOD = 1e9 + 7;
int n, m, a[N][N], dis[N][N];
vector<pair<int, int> > g[N], g1[N], inv[N];
void dijk(int source){
    dis[source][source] = 0;
    priority_queue<pair<int, pair<int, bool> >, vector<pair<int, pair<int, bool> > >, greater<pair<int, pair<int     
    pq.push({0, {source, 0}});
    vector<vector<bool> > vis(n + 1, vector<bool>(2, 0));
    while(!pq.empty()){
        pair<int, pair<int, bool> > cur = pq.top();
        pq.pop();
        if(vis[cur.S.F][cur.S.S]) continue;
        vis[cur.S.F][cur.S.S] = true;
        if(!cur.S.S){
            for(auto k : g[cur.S.F]){
                if(dis[source][k.F] > cur.F + k.S){
                    dis[source][k.F] = cur.F + k.S;
                    pq.push({dis[source][k.F], {k.F, cur.S.S}});
                }
            }
            for(auto k : g1[cur.S.F]){
                if(dis[source][k.F] > cur.F + k.S){
                    dis[source][k.F] = cur.F + k.S;
                    pq.push({dis[source][k.F], {k.F, 1}});
                }
            }
        }
        else{
            for(auto k : inv[cur.S.F]){
                if(dis[source][k.F] > cur.F + k.S){
                    dis[source][k.F] = cur.F + k.S;
                    pq.push({dis[source][k.F], {k.F, cur.S.S}});
                }
            }
        }
    }
}
void solve(){
    cin >> n >> m;
    for(int i = 0; i <= n; ++i){
        g[i].clear();
        inv[i].clear();
        g1[i].clear();
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
            dis[i][j] = LLONG_MAX;
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j) continue;
            g1[i].pb({j, 2 * (i - j) * (i - j)});
        }
    }
    for(int i = 1; i <= m; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        g[u].pb({v, c});
        inv[v].pb({u, c});
    }
    for(int i = 1; i <= n; ++i)
        dijk(i);
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j < i; ++j)
            ans += min(dis[a[j][i]][a[i][j]], dis[a[i][j]][a[j][i]]);
    }
    cout << ans << "\n";
}
int32_t main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}