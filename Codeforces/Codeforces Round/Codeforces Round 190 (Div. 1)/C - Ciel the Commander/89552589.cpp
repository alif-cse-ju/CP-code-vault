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
 char ans[N+2];
 void NewDFS(int cur,int par)
{
    if(cur == par)ans[cur]='A';
    else ans[cur]=(char)(ans[par]+1);
    for(int x : decomposedTree[cur])NewDFS(x,cur);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,x,y;
    cin >> n;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    int root=CentroidDecomposition(n);
    NewDFS(root,root);
    for(i=1;i<=n;i++)cout << ans[i] << ' ';
    return 0;
}