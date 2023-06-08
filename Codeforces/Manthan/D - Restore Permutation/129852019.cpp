#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=4e6+5;
const int mod=1e9+7;
int ans[M];
ll _tree[4*M],lazy[4*M];
void Propagate(int nodeNum,int start,int end)
    if(lazy[nodeNum] != 0)
    {
        _tree[nodeNum]+=lazy[nodeNum];
        if(start != end)
        {
            lazy[nodeNum*2]+=lazy[nodeNum];
            lazy[nodeNum*2 + 1]+=lazy[nodeNum];
        }
        lazy[nodeNum]=0;
    }
void Update(int nodeNum,int start,int end,int l,int r,ll value)
{
    Propagate(nodeNum,start,end);
    if(start > end  ||  start > r  ||  end < l)return;
    if(start >= l  &&  end <= r)
    {
        _tree[nodeNum]+=value;
        if(start != end)
        {
            lazy[nodeNum*2]+=value;
            lazy[nodeNum*2 + 1]+=value;
        }
        return;
    }
     int mid=(start+end)/2;
    Update(nodeNum*2,start,mid,l,r,value);
    Update(nodeNum*2 + 1,mid+1,end,l,r,value);
    _tree[nodeNum]=min(_tree[2*nodeNum],_tree[2*nodeNum+1]);
}
 int Query(int nodeNum,int start,int end)
{
    Propagate(nodeNum,start,end);
    if(start == end)return start;
    int mid=(start+end)/2;
    Propagate(2*nodeNum,start,mid);
    Propagate(2*nodeNum+1,mid+1,end);
    if(_tree[nodeNum] != _tree[2*nodeNum+1])return Query(nodeNum*2,start,mid);
    return Query(nodeNum*2+1,mid+1,end);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x;
    int i,l,n;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        Update(1,1,n,i,i,x);
    }
    for(i=1;i<=n;i++)
    {
        l=Query(1,1,n);
        ans[l]=i;
        if(l < n)Update(1,1,n,l+1,n,-i);
        Update(1,1,n,l,l,1e18);
    }
    for(i=1;i<=n;i++)cout << ans[i] << ' ';
    return 0;
}