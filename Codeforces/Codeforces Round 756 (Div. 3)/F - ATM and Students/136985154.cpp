#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
ll a[M],sum[M],node[4*M];
void Build(int nodeNum,int l,int r)
    if(l == r)
    {
        node[nodeNum]=sum[l];
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    node[nodeNum]=min(node[2*nodeNum],node[2*nodeNum+1]);
ll Query(int nodeNum,int start,int end,int l,int r)
{
    if(l == start  &&  r == end)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return Query(nodeNum*2,start,mid,l,r);
    if(mid < l)return Query(nodeNum*2+1,mid+1,end,l,r);
    return min(Query(nodeNum*2,start,mid,l,mid),Query(nodeNum*2+1,mid+1,end,mid+1,r));
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll s,v;
    int ans,i,id,l,m,n,r,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        for(i=1;i<=n;i++)cin >> a[i], sum[i]=sum[i-1]+a[i];
        Build(1,1,n);
        ans=0;
        for(i=1;i<=n;i++)
        {
            l=i,r=n;
            while(l <= r)
            {
                m=(l+r) >> 1;
                v=Query(1,1,n,i,m);
                if(s >= sum[i-1]-v)l=m+1;
                else r=m-1;
            }
            if(l-i > ans)ans=l-i, id=i;
        }
        if(!ans)cout << "-1\n";
        else cout << id << ' ' << id+ans-1 << '\n';
    }
    return 0;
}