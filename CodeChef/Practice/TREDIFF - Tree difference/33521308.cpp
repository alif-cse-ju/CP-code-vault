#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<vector<int> >up;
vector<int>adj[200005];
int l,timer,parent[200005],tin[200005],tout[200005],val[200005];
void dfs(int node,int par)
{
    parent[node]=par;
    tin[node]=++timer;
    up[node][0]=par;
    for(int i=1;i<=l;i++)up[node][i]=up[up[node][i-1]][i-1];
    for(int x : adj[node])
    {
        if(x != par)dfs(x,node);
    }
    tout[node]=++timer;
}
bool is_ancestor(int u,int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u,int v)
{
    if(is_ancestor(u,v))return u;
    if(is_ancestor(v,u))return v;
    for(int i=l;i>=0;--i)
    {
        if(!is_ancestor(up[u][i],v))u=up[u][i];
    }
    return up[u][0];
}
int main()
{
    FAST();
    int i,n,t,q,x,y,z,mx,ans;
    vector<int>nodes;
    cin >> t;
    while(t--)
    {
        set<int>st;
        cin >> n >> q;
        for(i=1;i<=n;i++)
        {
            cin >> val[i];
            adj[i].clear();
            st.insert(val[i]);
        }
        mx=st.size();
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        timer=0;
        l=ceil(log2(n));
        up.assign(n+1,vector<int>(l+1));
        dfs(1,1);
        while(q--)
        {
            cin >> x >> y;
            z=lca(x,y);
            nodes.clear();
            while(x != z  &&  nodes.size() <= mx)
            {
                nodes.emplace_back(val[x]);
                x=parent[x];
            }
            while(y != z  &&  nodes.size() <= mx)
            {
                nodes.emplace_back(val[y]);
                y=parent[y];
            }
            nodes.emplace_back(val[z]);
            if(nodes.size() > mx)cout << "0\n";
            else
            {
                ans=INT_MAX;
                sort(nodes.begin(),nodes.end());
                n=nodes.size();
                for(i=1;i<n;i++)ans=min(ans,nodes[i]-nodes[i-1]);
                cout << ans << '\n';
            }
        }
    }
    return 0;
}