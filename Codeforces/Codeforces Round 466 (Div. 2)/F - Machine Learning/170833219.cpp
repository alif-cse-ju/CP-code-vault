#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=1e6+5;
const int mod=1e9+7;
///Mo's part
const int magic = 2341;
int lastVal[M];
bool visited[M];
struct Query
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
            if(r/magic == q.r/magic)return ((r/magic) & 1) ? (updateCnt > q.updateCnt) : (updateCnt < q.updateCnt);
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
 int a[M],ans[M],freq[M],freqOfFreq[M];
 void Increment(int x)
{
    --freqOfFreq[freq[x]];
    ++freq[x], ++freqOfFreq[freq[x]];
}
 void Decrement(int x)
{
    --freqOfFreq[freq[x]];
    --freq[x], ++freqOfFreq[freq[x]];
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
 int distCnt;
map<int,int>mp;
 int Compress(int x)
{
    if(mp.find(x) == mp.end())mp[x]=++distCnt;
    return mp[x];
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;cin >> n >> q;
    for(int i=1;i<=n;i++)cin >> a[i], a[i]=Compress(a[i]), lastVal[i]=a[i];
    int queryCnt=0, updateCnt=0;
    while(q--)
    {
        int t;cin >> t;
        if(t == 1)
        {
            int l,r;cin >> l >> r;
            ++queryCnt;
            queries[queryCnt] = Query(l, r, queryCnt, updateCnt);
        }
        else
        {
            int i,x; cin >> i >> x, x=Compress(x);
            updates[++updateCnt] = Update(i, lastVal[i], x);
            lastVal[i] = x;
        }
    }
    sort(queries+1, queries+queryCnt+1);
     int l=1, r=1, updatesProcessed=0;
     for(int i=1;i<=queryCnt;i++)
    {
        while(queries[i].updateCnt < updatesProcessed)Delete(updatesProcessed--);
        while(queries[i].updateCnt > updatesProcessed)Add(++updatesProcessed);
        while(queries[i].l < l)Upd(--l);
        while(queries[i].r >= r)Upd(r++);
        while(queries[i].l > l)Upd(l++);
        while(queries[i].r+1 < r)Upd(--r);
         int mex=1;
        while(freqOfFreq[mex])++mex;
         ans[queries[i].id]=mex;
    }
     for(int i=1;i<=queryCnt;i++)cout << ans[i] << '\n';
    return 0;
}