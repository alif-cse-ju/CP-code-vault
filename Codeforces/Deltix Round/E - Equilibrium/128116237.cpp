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
const int M=1e5+5;
const int N=1e6+5;
const int mod=998244353;
ll a[M],b[M],dif[M];
pair<ll,ll>node[4*M];
void Build(int nodeNum,int l,int r)
    if(l == r)
    {
        node[nodeNum].first=node[nodeNum].second=dif[l];
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    node[nodeNum].first=max(node[2*nodeNum].first,node[2*nodeNum+1].first);
    node[nodeNum].second=min(node[2*nodeNum].second,node[2*nodeNum+1].second);
 pair<ll,ll>Query(int nodeNum,int start,int end,int l,int r)
{
    if(l == start  &&  r == end)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return Query(nodeNum*2,start,mid,l,r);
    if(mid < l)return Query(nodeNum*2+1,mid+1,end,l,r);
    pair<ll,ll>a,b;
    a=Query(nodeNum*2,start,mid,l,mid);
    b=Query(nodeNum*2+1,mid+1,end,mid+1,r);
    return {max(a.first,b.first),min(a.second,b.second)};
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,n,q,r;
    pair<ll,ll>ans;
    cin >> n >> q;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)cin >> b[i];
    for(i=1;i<=n;i++)dif[i]=dif[i-1]+a[i]-b[i];
    Build(1,1,n);
    while(q--)
    {
        cin >> l >> r;
        if(dif[r]-dif[l-1])cout << "-1\n";
        else
        {
            ans=Query(1,1,n,l,r);
            if(ans.first > dif[l-1])cout << "-1\n";
            else cout << dif[l-1]-ans.second << '\n';
        }
    }
    return 0;
}