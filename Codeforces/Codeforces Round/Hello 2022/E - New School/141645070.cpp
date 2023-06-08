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
const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int sz[M];
vector<ll>v[M];
ll a[M],avg[M],lazy[4*M],sum[M],_tree[4*M];
void Update(int nodeNum,int start,int end,int l,int r,ll value)
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
 ll Query(int nodeNum,int start,int end,int l,int r)
{
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
    if(start >= l  &&  end <= r)return _tree[nodeNum];
    int mid=(start+end)/2;
    if(r <= mid)return Query(nodeNum*2,start,mid,l,r);
    else if(l > mid)return Query(nodeNum*2+1,mid+1,end,l,r);
    return min(Query(nodeNum*2,start,mid,l,mid),Query(nodeNum*2 + 1,mid+1,end,mid+1,r));
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,m,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)cin >> a[i], Update(1,1,M-5,1,a[i],1);
        for(i=1;i<=m;i++)
        {
            cin >> sz[i];
            v[i].clear(), sum[i]=0;
            for(j=0;j<sz[i];j++)cin >> x, v[i].emplace_back(x), sum[i] += x;
            avg[i]=(sum[i]+sz[i]-1)/sz[i];
            Update(1,1,M-5,1,avg[i],-1);
        }
        for(i=1;i<=m;i++)
        {
            Update(1,1,M-5,1,avg[i],1);
            for(int it : v[i])
            {
                sum[i] -= it, --sz[i];
                Update(1,1,M-5,1,(sum[i]+sz[i]-1)/sz[i],-1);
                 cout << (_tree[1] >= 0);
                 Update(1,1,M-5,1,(sum[i]+sz[i]-1)/sz[i],1);
                sum[i] += it, ++sz[i];
            }
            Update(1,1,M-5,1,avg[i],-1);
        }
        for(i=1;i<=n;i++)Update(1,1,M-5,1,a[i],-1);
        for(i=1;i<=m;i++)Update(1,1,M-5,1,avg[i],1);
        cout << '\n';
    }
    return 0;
}