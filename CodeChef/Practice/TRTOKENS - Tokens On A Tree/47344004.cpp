#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;
char s[M];
long long ans;
vector<int>adj[M];
pair<int,int>node[4*M];
int cnt,dep[M],L[M],n,R[M];
void Build(int nodeNum,int l,int r)
{
    node[nodeNum]={0,0};
    if(l == r)return;
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
}
void Update(int nodeNum,int start,int end,int pos,int x)
{
    if(start == end)
    {
        node[nodeNum]={x,pos};
        return;
    }
    int mid=(start+end) >> 1;
    if(pos <= mid)Update(2*nodeNum,start,mid,pos,x);
    else Update(2*nodeNum+1,mid+1,end,pos,x);
    node[nodeNum]=max(node[2*nodeNum],node[2*nodeNum+1]);
}
pair<int,int> Query(int nodeNum,int start,int end,int l,int r)
{
    if(l == start  &&  r == end)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return Query(nodeNum*2,start,mid,l,r);
    if(mid < l)return Query(nodeNum*2+1,mid+1,end,l,r);
    return max(Query(nodeNum*2,start,mid,l,mid),Query(nodeNum*2+1,mid+1,end,mid+1,r));
}
void DFS(int x,int p)
{
    L[x]=++cnt,dep[x]=dep[p]+1;
    for(int y : adj[x])DFS(y,x);
    R[x]=cnt;
    if(s[x] == '1')Update(1,1,n,L[x],dep[x]);
    else
    {
        auto [val,idx]=Query(1,1,n,L[x],R[x]);
        if(val)
        {
            ans+=val-dep[x];
            Update(1,1,n,idx,0);
            Update(1,1,n,L[x],dep[x]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> s+1;
        for(i=1;i<=n;i++)adj[i].clear();
        for(i=2;i<=n;i++)
        {
            cin >> x;
            adj[x].emplace_back(i);
        }
        ans=cnt=0;
        Build(1,1,n);
        DFS(1,0);
        cout << ans << '\n';
    }
    return 0;
}