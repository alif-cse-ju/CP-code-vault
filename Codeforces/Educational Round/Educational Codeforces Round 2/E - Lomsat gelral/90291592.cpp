#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int>adj[N+2];
bool bigChildMark[N+2];
long long sum,ans[N+2];
int maxx,color[N+2],colorCnt[N+2],sz[N+2];
void DFS(int cur,int par)
    sz[cur]=1;
    for(int x : adj[cur])
    {
        if(x ^ par)
        {
            DFS(x,cur);
            sz[cur]+=sz[x];
        }
    }
void Add(int cur,int par,int val)
    colorCnt[color[cur]]+=val;
    if(colorCnt[color[cur]] > maxx)
    {
        sum=color[cur];
        maxx=colorCnt[color[cur]];
    }
    else if(colorCnt[color[cur]] == maxx)sum+=color[cur];
    for(int x : adj[cur])
    {
        if((x ^ par)  &&  !bigChildMark[x])Add(x,cur,val);
    }
void DFS(int cur,int par,bool keep)
{
    int bigChild=0,mx=0;
    for(int x : adj[cur])
    {
        if((x ^ par)  &&  sz[x] > mx)
        {
            mx=sz[x];
            bigChild=x;
        }
    }
    for(int x : adj[cur])
    {
        if((x ^ par)  &&  (x ^ bigChild))DFS(x,cur,0);//clearing small childs from cnt
    }
    if(bigChild)DFS(bigChild,cur,1),bigChildMark[bigChild]=1;
    Add(cur,par,1);
    //now cnt[c] is the number of vertices in subtree of vertex cur that has color c.
    ans[cur]=sum;
    if(bigChild)bigChildMark[bigChild]=0;
    if(!keep)Add(cur,par,-1),maxx=sum=0;
}
 void DSUonTree()
{
    DFS(1,0);
    DFS(1,0,1);
}
 int main()
{
    int i,n,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&color[i]);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    DSUonTree();
    for(i=1;i<=n;i++)printf("%lld ",ans[i]);
    return 0;
}