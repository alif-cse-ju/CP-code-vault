#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
vector<int>adj[N];
int n,LG,dist[N],dp[N][20];
void DFS1(int cur,int par)
{
    dist[cur]=dist[par]+1;
    dp[cur][0]=par;
    for(int i=1; i<=LG; i++)dp[cur][i]=dp[dp[cur][i-1]][i-1];
    for(int x : adj[cur])
    {
        if(x ^ par)DFS1(x,cur);
    }
}
void PreCal()
{
    LG=ceil(log2(n));
    dist[1]=-1;
    DFS1(1,1);
}
int FindKth(int node,int k)
{
    for(int i=LG; i>=0; i--)
    {
        if((1 << i) <= k)
        {
            k-=(1 << i);
            node=dp[node][i];
        }
    }
    return node;
}
int l,timer,inTime[N],outTime[N],up[N][20];
void DFS2(int cur,int par)
{
    inTime[cur]=++timer;
    up[cur][0]=par;
    for(int i=1;i<=l;i++)up[cur][i]=up[up[cur][i-1]][i-1];
    for(int x : adj[cur])
    {
        if(x ^ par)DFS2(x,cur);
    }
    outTime[cur]=++timer;
}
bool IsAncestor(int x,int y)
{
    return inTime[x] <= inTime[y]  &&  outTime[x] >= outTime[y];
}
int LCA(int x,int y)
{
    if(IsAncestor(x,y))return x;
    if(IsAncestor(y,x))return y;
    for(int i=l;i>=0;i--)
    {
        if(!IsAncestor(up[x][i],y))x=up[x][i];
    }
    return up[x][0];
}
void PreProcess()
{
    l=ceil(log2(n));
    DFS2(1,1);
}
bool Compare(int &x,int &y)
{
    return dist[x] <= dist[y];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool val;
    int i,k,t,q,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1; i<=n; i++)adj[i].clear();
        for(i=1; i<n; i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        PreCal();
        PreProcess();
        cin >> q;
        while(q--)
        {
            cin >> k;
            vector<int>v1,v2;
            for(i=0; i<k; i++)
            {
                cin >> x;
                v1.emplace_back(x);
            }
            sort(v1.begin(),v1.end(),Compare);
            for(i=0; i<k-1; i++)
            {
                if(FindKth(v1[k-1],dist[v1[k-1]]-dist[v1[i]]) != v1[i])v2.emplace_back(v1[i]);
            }
            k=(int)v2.size()-1;
            for(i=0; i<k; i++)
            {
                if(FindKth(v2[k],dist[v2[k]]-dist[v2[i]]) != v2[i])break;
            }
            if(i >= k)
            {
                if(k < 0)cout << "YES\n";
                else
                {
                    val=1;
                    k=LCA(v1.back(),v2.back());
                    for(int it : v1)
                    {
                        if(dist[it] < dist[k])
                        {
                            val=0;
                            break;
                        }
                    }
                    if(val)cout << "YES\n";
                    else cout << "NO\n";
                }
            }
            else cout << "NO\n";
        }
    }
    return 0;
}