#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=2e6+5;
const int mod=998244353;
int n;
ll a[M],lazy[4*M],lazySum[M],segTree[4*M];
void Update(int i, ll val)
    while(i <= n)lazySum[i]+=val, i+=(i & -i);
ll Query(int i)
    ll ans=0;
    while(i)ans+=lazySum[i], i-=(i & -i);
    return ans;
void Push(int nodeNum,int l,int r)
{
    ll len=r-l+1;
    segTree[nodeNum] += lazy[nodeNum] * ((len*(len+1))/2);
    if(l != r)
    {
        lazy[2*nodeNum]+=lazy[nodeNum];
        lazy[2*nodeNum+1]+=lazy[nodeNum];
         int m=(l+r) >> 1;
        Update(m+1, lazy[nodeNum]*(m-l+1)), Update(r+1, lazy[nodeNum]*(-m+l-1));
    }
    lazy[nodeNum]=0;
}
 void Update(int nodeNum,int start,int end,int l,int r,ll val)
{
    Push(nodeNum,start,end);
    if(start == l  &&  end == r)
    {
        lazy[nodeNum] += val;
        Push(nodeNum,l,r);
        return;
    }
    int m=(start+end) >> 1;
    if(r <= m)
    {
        Update(2*nodeNum,start,m,l,r,val);
        Update(2*nodeNum+1,m+1,end,m+1,end,0);
    }
    else if(l > m)
    {
        Update(2*nodeNum,start,m,start,m,0);
        Update(2*nodeNum+1,m+1,end,l,r,val);
    }
    else
    {
        Update(2*nodeNum,start,m,l,m,val);
        Update(m+1,val*(m-l+1)), Update(r+1,val*(-m+l-1));
        Update(2*nodeNum+1,m+1,end,m+1,r,val);
    }
    segTree[nodeNum] = segTree[2*nodeNum]+segTree[2*nodeNum+1];
}
 ll Query(int nodeNum,int start,int end,int l,int r)
{
    Push(nodeNum,start,end);
    if(start >= l  &&  end <= r)return segTree[nodeNum];
    int m=(start+end) >> 1;
    if(r <= m)return Query(2*nodeNum,start,m,l,r);
    if(l > m)return Query(2*nodeNum+1,m+1,end,l,r);
    return Query(2*nodeNum,start,m,l,m) + Query(2*nodeNum+1,m+1,end,m+1,r);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> n >> k;
    for(int i=1;i<=n;i++)cin >> a[i];
    ll ans=0;
    for(int i=n;i;i--)
    {
        ll val=Query(1,1,n,i,i) + Query(i);
        if(val >= a[i])continue;
        int l=max(1, i-k+1), r=i;
        val=(a[i]-val+r-l)/(r-l+1), ans+=val;
        Update(1,1,n,l,r,val);
    }
    cout << ans;
    return 0;
}