#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#ifdef APURBA
#include "DEBUG_TEMPLATE.h"
#else
#define HERE
#define debug(args...)
#endif
const int N = 1000 +5;
typedef pair<int,int> pii;
int n;
vector<vector<int> >adj;
vector<int>sz;
vector<bool>vis;
int query(int i)
{
    i++;
    printf("? %d\n",i);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    if(x!=-1)
        x--;
    return x;
}
void print(int i)
{
    i++;
    printf("! %d\n",i);
    fflush(stdout);
}
void build(int s, int p);
void dfs2(int s, int p, int c,bool &ok);
void dfs(int s, int p);
int centroid(int s,int  p, int total);
void init()
{
    sz.clear();
    vis.clear();
    sz.resize(n);
    vis.resize(n,false);
    build(0,-1);
}
void build(int s, int p)
{
    dfs(s,p);
    int c= centroid(s,p,sz[s]);
    vis[c]= true;
    int x  = query(c);
    if(x==-1)
    {
        print(c);
        return;
    }
    for(auto it:adj[c])
    {
        if(vis[it])
            continue;
        bool ok = 0;
        dfs2(it,c,x,ok);
        if(ok)
        {
            build(it,c);
            break;
        }
    }
}
void dfs2(int s, int p, int c,bool &ok)
{
    if(s==c)
        ok = 1;
    for(auto i:adj[s])
    {
        if(i==p || vis[i])
            continue;
        dfs2(i,s,c,ok);
    }
}
void dfs(int s, int p)
{
    sz[s] = 1;
    for(auto i:adj[s])
    {
        if(i==p || vis[i])
            continue;
        dfs(i,s);
        sz[s]+= sz[i];
    }
}
int centroid(int s,int  p, int total)
{
    for(auto i:adj[s])
    {
        if(i==p || vis[i])
            continue;
        if(sz[i]*2>total)
            return centroid(i,s,total);
    }
    return s;
}
void TEST_CASES()
{
    scanf("%d",&n);
    adj.clear();
    adj.resize(n);
    for(int i=0; i<n-1; i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    init();
}
int32_t main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)
    {
        TEST_CASES();
    }
    return 0;
}