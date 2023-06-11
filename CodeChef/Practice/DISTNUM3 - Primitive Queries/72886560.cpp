#include<bits/stdc++.h>
using namespace std;
const int M=3e5+5;
///Mo's part
const int magic = 2143;
int lastVal[M];
bool visited[M];
struct Query
{
    int id,l,r,updateCnt;
    Query() {}
    Query(int _l,int _r,int _id,int _updateCnt)
    {
        l=_l, r=_r, id=_id, updateCnt=_updateCnt;
    }
    bool operator < (const Query& q)
    {
        if(l/magic == q.l/magic)
        {
            if(r/magic == q.r/magic)return ((r/magic) & 1) ? (updateCnt > q.updateCnt) : (updateCnt < q.updateCnt
            return r/magic < q.r/magic;
        }
        return l/magic < q.l/magic;
    }
} queries[M];
struct Update
{
    int id,prevVal,val;
    Update() {}
    Update(int _id,int _prevVal,int _val)
    {
        id=_id, prevVal=_prevVal, val=_val;
    }
} updates[M];
///Mo's part
///LCA part
vector<int>adj[M];
int l,timer,inTime[M],outTime[M],up[M][20];
void DFS(int cur,int par)
{
    inTime[cur]=++timer;
    up[cur][0]=par;
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
///LCA part
map<int,int>distinct;
int a[M],ansCnt,ans[M],distCnt,freq[M],lca[M],nodeAt[M];
int Compress(int x)
{
    if(distinct.find(x) == distinct.end())distinct[x] = ++distCnt;
    return distinct[x];
}
void Increment(int x)
{
    ++freq[x];
    if(freq[x] == 1)++ansCnt;
}
void Decrement(int x)
{
    --freq[x];
    if(!freq[x])--ansCnt;
}
void Upd(int x)
{
    int y = a[x];
    if(!visited[x])Increment(y);
    else Decrement(y);
    visited[x] = 1-visited[x];
}
void Add(int i)
{
    int id=updates[i].id, x=updates[i].val;
    if(visited[id])Decrement(a[id]);
    a[id] = x;
    if(visited[id])Increment(a[id]);
}
void Delete(int i)
{
    int id=updates[i].id, x=updates[i].prevVal;
    if(visited[id])Decrement(a[id]);
    a[id] = x;
    if(visited[id])Increment(a[id]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;cin >> n >> q;
    for(int i=1;i<=n;i++)cin >> a[i], a[i]=Compress(a[i]), lastVal[i]=a[i];
    for(int i=1;i<n;i++)
    {
        int x,y;cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    PreProcess(n, 1);
    int queryCnt=0, updateCnt=0;
    while(q--)
    {
        int t;cin >> t;
        if(t == 1)
        {
            int x,y;cin >> x >> y;
            ++queryCnt;
            int _lca=LCA(x,y);
            queries[queryCnt].id = queryCnt;
            queries[queryCnt].updateCnt = updateCnt;
            if(_lca == x)
            {
                queries[queryCnt].l = inTime[x];
                queries[queryCnt].r = inTime[y];
            }
            else if(_lca == y)
            {
                queries[queryCnt].l = inTime[y];
                queries[queryCnt].r = inTime[x];
            }
            else
            {
                lca[queryCnt] = _lca;
                if(inTime[x] > inTime[y])swap(x, y);
                queries[queryCnt].l = outTime[x];
                queries[queryCnt].r = inTime[y];
            }
        }
        else
        {
            int i,x; cin >> i >> x;
            x = Compress(x), ++updateCnt;
            updates[updateCnt] = Update(i, lastVal[i], x);
            lastVal[i] = x;
        }
    }
    sort(queries+1, queries+queryCnt+1);
    int l=1, r=1, updatesProcessed=0;
    for(int i=1;i<=n;i++)nodeAt[inTime[i]] = nodeAt[outTime[i]] = i;
    for(int i=1;i<=queryCnt;i++)
    {
        while(queries[i].updateCnt < updatesProcessed)Delete(updatesProcessed--);
        while(queries[i].updateCnt > updatesProcessed)Add(++updatesProcessed);
        while(queries[i].l < l)Upd(nodeAt[--l]);
        while(queries[i].r >= r)Upd(nodeAt[r++]);
        while(queries[i].l > l)Upd(nodeAt[l++]);
        while(queries[i].r+1 < r)Upd(nodeAt[--r]);
        if(lca[queries[i].id])Upd(lca[queries[i].id]);
        ans[queries[i].id] = ansCnt;
        if(lca[queries[i].id])Upd(lca[queries[i].id]);
    }
    for(int i=1;i<=queryCnt;i++)cout << ans[i] << '\n';
    return 0;
}