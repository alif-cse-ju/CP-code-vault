#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+45;
 int n,k,a;
int spc[N];
vector <int> g[N];
int has[N];
int dep[N],closest[N],spnode[N];
 void prep(int x,int par){
    has[x] |= spc[x];
     int spn = 0;
    for(auto f : g[x]){
        if(f == par) continue;
        dep[f] = dep[x]+1;
        prep(f,x);
        has[x] |= has[f];
        if(has[f]) spn = spnode[f];
    }
     if(spc[x]) spnode[x] = x;
    else spnode[x] = spn;
}
 void dfs(int x,int par){
    if(has[x]) closest[x] = x;
    else closest[x] = closest[par];
    for(auto f : g[x]){
        if(f == par) continue;
        dfs(f,x);
    }
}
 void solve(){
    cin >> n >> k >> a;
    for(int i = 1; i <= n; i++){
        g[i].clear();
        spc[i] = dep[i] = closest[i] = has[i] = spnode[i] = 0;
    }
     for(int i = 1; i <= k; i++){
        int x;
        cin >> x;
        spc[x] = 1;
    }
     for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
     dep[a] = 0;
    prep(a,0);
    dfs(a,0);
     for(int i = 1; i <= n; i++){
        int maxval = 2*dep[closest[i]]-dep[i];
        cout << maxval;
        if(i < n) cout << " ";
        else cout << endl;
    }
     for(int i = 1; i <= n; i++){
        cout << spnode[closest[i]];
        if(i < n) cout << " ";
        else cout << endl;
    }
}
 int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}