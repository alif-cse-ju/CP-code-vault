#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
char s[N+2];
string ans[N+2];
vector<int>adj[N+2];
bool bigChildMark[N+2];
vector<pair<int,int>>queries[N+2];
int color[N+2],colorCnt[N+2][30],height[N+2],sz[N+2];
void DFS(int cur,int par)
    sz[cur]=1;
    height[cur]=height[par]+1;
    for(int x : adj[cur])
    {
        DFS(x,cur);
        sz[cur]+=sz[x];
    }
void Add(int cur,int par,int val)
    colorCnt[height[cur]][color[cur]]+=val;
    for(int x : adj[cur])
    {
        if(!bigChildMark[x])Add(x,cur,val);
    }
void DFS(int cur,int par,bool keep)
    int bigChild=0,mx=0;
    for(int x : adj[cur])
    {
        if(sz[x] > mx)
        {
            mx=sz[x];
            bigChild=x;
        }
    }
    for(int x : adj[cur])
    {
        if(x ^ bigChild)DFS(x,cur,0);//clearing small childs from cnt
    }
    if(bigChild)DFS(bigChild,cur,1),bigChildMark[bigChild]=1;
    Add(cur,par,1);
    //now cnt[c] is the number of vertices in subtree of vertex cur that has color c.
    int i,x,y,cnt;
    for(auto it : queries[cur])
    {
        cnt=0;
        x=it.first,y=it.second;
        for(i=1;i<27;i++)cnt+=colorCnt[x][i] & 1;
        if(cnt < 2)ans[y]="Yes";
        else ans[y]="No";
    }
    if(bigChild)bigChildMark[bigChild]=0;
    if(!keep)Add(cur,par,-1);
}
 void DSUonTree()
{
    DFS(1,0);
    DFS(1,0,1);
}
 int main()
{
    int i,n,q,x,y;
    scanf("%d %d",&n,&q);
    for(i=2;i<=n;i++)
    {
        scanf("%d",&x);
        adj[x].emplace_back(i);
    }
    scanf("%s",s+1);
    for(i=1;i<=n;i++)color[i]=s[i]-'a'+1;
    for(i=1;i<=q;i++)
    {
        scanf("%d %d",&x,&y);
        queries[x].emplace_back(y,i);
    }
    DSUonTree();
    for(i=1;i<=q;i++)cout << ans[i] << '\n';
    return 0;
}