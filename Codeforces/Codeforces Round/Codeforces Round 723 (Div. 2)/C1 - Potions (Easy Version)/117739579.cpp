#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
///BIT
int n;
long long sum[N];
void BitUpdate(int i,int val)
    while(i <= n)
    {
        sum[i]+=val;
        i+=i & (-i);
    }
long long BitQuery(int i)
    long long ans=0;
    while(i)
    {
        ans+=sum[i];
        i-=i & (-i);
    }
    return ans;
}
 ///BIT
 ///Segment Tree Lazy
 long long cum[N],node[4*N],lazy[4*N];
 void Build(int nodeNum,int l,int r)
{
    if(l == r)
    {
        node[nodeNum]=cum[l];
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    node[nodeNum]=min(node[2*nodeNum],node[2*nodeNum+1]);
}
 void SegUpdate(int nodeNum,int start,int end,int l,int r,long long value)
{
    if(lazy[nodeNum] != 0)
    {
        node[nodeNum]+=lazy[nodeNum];
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
        node[nodeNum]+=value;
        if(start != end)
        {
            lazy[nodeNum*2]+=value;
            lazy[nodeNum*2 + 1]+=value;
        }
        return;
    }
     int mid=(start+end)/2;
    SegUpdate(nodeNum*2,start,mid,l,r,value);
    SegUpdate(nodeNum*2 + 1,mid+1,end,l,r,value);
     node[nodeNum]=min(node[nodeNum*2] , node[nodeNum*2 + 1]);
}
 long long SegQuery(int nodeNum,int start,int end,int l,int r)
{
    if(start > end  ||  start > r  ||  end < l)return LLONG_MAX;
    if(lazy[nodeNum] != 0)
    {
        node[nodeNum]+=lazy[nodeNum];
        if(start != end)
        {
            lazy[nodeNum*2]+=lazy[nodeNum];
            lazy[nodeNum*2 + 1]+=lazy[nodeNum];
        }
        lazy[nodeNum]=0;
    }
    if(start >= l  &&  end <= r)return node[nodeNum];
     int mid=(start+end)/2;
    long long ans1=SegQuery(nodeNum*2,start,mid,l,r);
    long long ans2=SegQuery(nodeNum*2 + 1,mid+1,end,l,r);
     return min(ans1,ans2);
}
 ///Segment Tree Lazy
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,x,ans=0;
    vector<pair<int,int>>v;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        if(x >= 0)BitUpdate(i,x),++ans;
        else v.emplace_back(-x,i);
        cum[i]=cum[i-1]+(x >= 0 ? x : 0);
    }
    Build(1,1,n);
    sort(v.begin(),v.end());
    for(auto [x,i] : v)
    {
        if(BitQuery(i) >= x  &&  SegQuery(1,1,n,i,n) >= x)++ans,BitUpdate(i,-x),SegUpdate(1,1,n,i,n,-x);
    }
    cout << ans;
    return 0;
}