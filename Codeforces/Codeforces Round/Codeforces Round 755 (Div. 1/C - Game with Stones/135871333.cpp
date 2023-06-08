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
const int mod=998244353;
int a[M];
ll _tree[4*M][2],lazy[4*M][2];
void Build(int nodeNum,int l,int r)
    lazy[nodeNum][0]=lazy[nodeNum][1]=0;
    if(l == r)
    {
        _tree[nodeNum][l & 1]=a[l];
        _tree[nodeNum][1-(l & 1)]=1e18;
        return;
    }
    int m=(l+r) >> 1;
    Build(2*nodeNum,l,m);
    Build(2*nodeNum+1,m+1,r);
    _tree[nodeNum][0]=min(_tree[2*nodeNum][0], _tree[2*nodeNum+1][0]);
    _tree[nodeNum][1]=min(_tree[2*nodeNum][1], _tree[2*nodeNum+1][1]);
}
 void Update(int nodeNum,int start,int end,int l,int r,int value,int id)
{
    if(start > end  ||  start > r  ||  end < l)return;
    if(start >= l  &&  end <= r)
    {
        _tree[nodeNum][id & 1] += value, lazy[nodeNum][id & 1] += value;
        _tree[nodeNum][1-(id & 1)] -= value, lazy[nodeNum][1-(id & 1)] -= value;
        return;
    }
    int mid=(start+end)/2;
    Update(nodeNum*2,start,mid,l,r,value,id);
    Update(nodeNum*2 + 1,mid+1,end,l,r,value,id);
    _tree[nodeNum][0] = min(_tree[2*nodeNum][0], _tree[2*nodeNum+1][0]);
    _tree[nodeNum][1] = min(_tree[2*nodeNum][1], _tree[2*nodeNum+1][1]);
}
 ll Query(int nodeNum,int start,int end,int l,int r,ll lazy0,ll lazy1)
{
    if(start >= l  &&  end <= r)return min(_tree[nodeNum][0]+lazy0, _tree[nodeNum][1]+lazy1);
    int mid=(start+end)/2;
    lazy0 += lazy[nodeNum][0], lazy1 += lazy[nodeNum][1];
    if(r <= mid)return Query(nodeNum*2,start,mid,l,r,lazy0,lazy1);
    else if(l > mid)return Query(nodeNum*2+1,mid+1,end,l,r,lazy0,lazy1);
    return min(Query(nodeNum*2,start,mid,l,mid,lazy0,lazy1), Query(nodeNum*2 + 1,mid+1,end,mid+1,r,lazy0,lazy1));
}
 ll dp[M];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans,tmp;
    int i,id,l,m,n,r,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        Build(1,1,n), dp[n+1]=0;
        for(i=n;i;i--)
        {
            Update(1,1,n,i+1,n,a[i],i);
            if(!a[i])dp[i]=1+dp[i+1];
            else
            {
                l=i+1,r=n,id=0;
                while(l <= r)
                {
                    m=(l+r) >> 1;
                    tmp=Query(1,1,n,i+1,m,0,0);
                    if(tmp > 0)l=m+1;
                    else r=m-1;
                    if(!tmp)id=m;
                }
                if(!id)dp[i]=0;
                else dp[i]=1+dp[id+1];
            }
        }
        ans=0;
        for(i=1;i<=n;i++)ans += dp[i];
        cout << ans << '\n';
    }
    return 0;
}