#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
/**********************Centroid Decomposition*****************************/
bool alreadyComposed[N+2];
int parent[N+2],subTreeSize[N+2];
vector<int>adj[N+2],decomposedTree[N+2];
void DFS(int cur)
    for(int x : adj[cur])
    {
        if(x ^ parent[cur])
        {
            parent[x]=cur;
            DFS(x);
            subTreeSize[cur]+=1+subTreeSize[x];
        }
    }
int Decompose(int cur,int size,int par)
    int nextNode,val;
    while(true)
    {
        nextNode=0;
        for(int x : adj[cur])
        {
            if(alreadyComposed[x]  ||  x == parent[cur])continue;
            if(subTreeSize[x] >= size/2)nextNode=x;
        }
        if(size-1-subTreeSize[cur] > size/2  &&  parent[cur]  &&  !alreadyComposed[parent[cur]])nextNode=parent[cur];
        if(nextNode)cur=nextNode;
        else break;
    }
    for(int x=parent[cur];x  &&  !alreadyComposed[x];x=parent[x])subTreeSize[x]-=1+subTreeSize[cur];
    alreadyComposed[cur]=1;
    for(int x : adj[cur])
    {
        if(alreadyComposed[x])continue;
        val=1+subTreeSize[x];
        if(x == parent[cur])val=size-1-subTreeSize[cur];
        decomposedTree[cur].emplace_back(Decompose(x,val,cur));
    }
    return cur;
}
 int CentroidDecomposition(int numberOfNodes)
{
    DFS(1);
    return Decompose(1,numberOfNodes,0);
}
 /**********************Centroid Decomposition*****************************/
 int ans[N+2],level[N+2],newParent[N+2];
 /**********************Lowest Common Ancestor*****************************/
 int l,timer,inTime[N+2],outTime[N+2],up[N+2][20];
 void DFS(int cur,int par)
{
    inTime[cur]=++timer;
    up[cur][0]=par;
    level[cur]=level[par]+1;
    for(int i=1;i<=l;i++)up[cur][i]=up[up[cur][i-1]][i-1];
    for(int x : adj[cur])
    {
        if(x ^ par)DFS(x,cur);
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
 void PreProcess(int numberOfNodes,int root)
{
    l=ceil(log2(numberOfNodes));
    DFS(root,root);
}
 /**********************Lowest Common Ancestor*****************************/
 void NewDFS(int cur,int par)
{
    newParent[cur]=par;
    for(int x : decomposedTree[cur])NewDFS(x,cur);
}
 int Dist(int x,int y)
{
    return level[x]+level[y]-2*level[LCA(x,y)];
}
 void Update(int cur)
{
    ans[cur]=0;
    for(int x=newParent[cur];x;x=newParent[x])ans[x]=min(ans[x],Dist(x,cur));
}
 int Query(int cur)
{
    int cnt=ans[cur];
    for(int x=newParent[cur];x;x=newParent[x])cnt=min(cnt,Dist(x,cur)+ans[x]);
    return cnt;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,q,x,y;
    cin >> n >> q;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    PreProcess(n,1);
    int root=CentroidDecomposition(n);
    NewDFS(root,0);
    for(i=1;i<=n;i++)ans[i]=1e7;
    Update(1);
    while(q--)
    {
        cin >> x >> y;
        if(x == 1)Update(y);
        else cout << Query(y) << '\n';
    }
    return 0;
}