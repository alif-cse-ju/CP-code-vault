#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define pb push_back
#define pii pair<int,int>
#define vp vector<pair<int,int>>
#define vi vector<int>
#define vii vector<vi>
#define tp tuple<double,int,int>
#define sd(a) scanf("%I64d",&a)
#define pr(a) printf("%d ",a)
#define mod 1000000007
#define INF 1000000000000000000
const double EPS = 1e-9;
// LCA template from Cp algorithms
struct LCA {
vector<int>height, euler, first, segtree;
vector<bool>visited;
int n;
LCA(vector<vector<int>> &adj, int root = 0) {
    n = adj.size();
    height.resize(n);
    first.resize(n);
    euler.reserve(n * 2);
    visited.assign(n, false);
    dfs(adj, root);
    int m = euler.size();
    segtree.resize(m * 4);
    build(1, 0, m - 1);
}
void dfs(vector<vector<int>> &adj, int node, int h = 0) {
    visited[node] = true;
    height[node] = h;
    first[node] = euler.size();
    euler.push_back(node);
    for (auto to : adj[node]) {
        if (!visited[to]) {
            dfs(adj, to, h + 1);
            euler.push_back(node);
        }
    }
}
void build(int node, int b, int e) {
    if (b == e) {
        segtree[node] = euler[b];
    } else {
        int mid = (b + e) / 2;
        build(node << 1, b, mid);
        build(node << 1 | 1, mid + 1, e);
        int l = segtree[node << 1], r = segtree[node << 1 | 1];
        segtree[node] = (height[l] < height[r]) ? l : r;
    }
}
int query(int node, int b, int e, int L, int R) {
    if (b > R || e < L)
        return -1;
    if (b >= L && e <= R)
        return segtree[node];
    int mid = (b + e) >> 1;
    int left = query(node << 1, b, mid, L, R);
    int right = query(node << 1 | 1, mid + 1, e, L, R);
    if (left == -1) return right;
    if (right == -1) return left;
    return height[left] < height[right] ? left : right;
}
int lca(int u, int v) {
    int left = first[u], right = first[v];
    if (left > right)
        swap(left, right);
    return query(1, 0, euler.size() - 1, left, right);
}
};
unordered_map<string,int> mp;
vi vis;
vi par;
void dfs(int u,vii &adj){
vis[u]=1;
for(int v:adj[u]){
if(!vis[v]){
par[v]=u;
dfs(v,adj);
}
}
}
int find(int from,int to){ // calculates dist(from,to)
if(from==to) return 0;
string s = to_string(from)+to_string(par[from]);
if(mp[s]) return mp[s];
return mp[s] + (mp[to_string(par[from])+to_string(to)]=find(par[from],to));
}
void solve(){
int n,m; cin>>n;
m=n-1;
vii adj(n+1); vis.resize(n+1); par.resize(n+1);
for(int i=0;i<m;i++){
int u,v,w; cin>>u>>v>>w;
string s = to_string(u)+to_string(v);
mp[s]=w; // stores distance between u and v
s = to_string(v)+to_string(u);
mp[s]=w;
adj[u].pb(v);
adj[v].pb(u);
}
par[1]=0;
dfs(1,adj);
LCA l(adj,1);
int x,y,z; cin>>x>>y>>z; 
int ans=1e18; int ans_node=1;
for(int i=1;i<=n;i++){
   int sum = 0;               // stores total cost for node i
   int lca_ele = l.lca(i,x);               // lca of mode i and x
   sum += (mp[to_string(i)+to_string(lca_ele)]=find(i,lca_ele)) +   (mp[to_string(x)+to_string(lca_ele)]=find(             
   lca_ele = l.lca(i,y);                    // lca of mode i and y                  
   sum += (mp[to_string(i)+to_string(lca_ele)]=find(i,lca_ele)) + (mp[to_string(y)+to_string(lca_ele)]=find(y,         
   lca_ele = l.lca(i,z);             // lca of mode i and z
   sum += (mp[to_string(i)+to_string(lca_ele)]=find(i,lca_ele)) + (mp[to_string(z)+to_string(lca_ele)]=find(z,        
     if(ans>sum){
    ans=sum; ans_node=i;
   }
}
cout<<ans_node;
}
int32_t main(){
#ifndef ONLINE_JUDGE
freopen(“input.txt”,“r”,stdin);
freopen(“output.txt”,“w”,stdout);
#endif
ios_base::sync_with_stdio(0);
cin.tie(0);
int t=1;
//cin>>t;
while(t--){
solve();
}
return 0;
}