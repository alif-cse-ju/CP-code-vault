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
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
pair<int,int>a[M],node[4*M];
void Build(int nodeNum,int l,int r)
    if(l == r)
    {
        node[nodeNum]={INT_MAX,INT_MAX};
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    node[nodeNum]=min(node[2*nodeNum],node[2*nodeNum+1]);
void Update(int nodeNum,int start,int end,int pos,int v)
    if(start == end)
    {
        node[nodeNum]={v,pos};
        return;
    }
    int mid=(start+end) >> 1;
    if(pos <= mid)Update(2*nodeNum,start,mid,pos,v);
    else Update(2*nodeNum+1,mid+1,end,pos,v);
    node[nodeNum]=min(node[2*nodeNum],node[2*nodeNum+1]);
}
 pair<int,int>Query(int nodeNum,int start,int end,int l,int r)
{
    if(l == start  &&  r == end)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return Query(nodeNum*2,start,mid,l,r);
    if(mid < l)return Query(nodeNum*2+1,mid+1,end,l,r);
    return min(Query(nodeNum*2,start,mid,l,mid),Query(nodeNum*2+1,mid+1,end,mid+1,r));
}
 int dp[M],id[M],r[M];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt=0,i,j,n,x;
    cin >> n;
    for(i=1;i<=n;i++)cin >> x, a[i]={x,i};
    sort(a+1,a+n+1);
    if(n < 6)
    {
        cout << a[n].first-a[1].first << ' ' << "1\n";
        while(n--)cout << "1 ";
        return 0;
    }
    Build(1,1,n);
    r[n]=r[n-1]=r[n-2]=n;
    Update(1,1,n,n,a[n].first);
    dp[n-2]=a[n].first-a[n-2].first;
    for(i=n-3;i;i--)
    {
        auto [v,ii]=Query(1,1,n,i+2,n);
        r[i]=ii, dp[i]=v-a[i].first, Update(1,1,n,i,a[i].first+dp[i+1]);
    }
    for(i=1;i<=n;i=j)
    {
        ++cnt;
        for(j=i;j<=r[i];j++)id[a[j].second]=cnt;
    }
    cout << dp[1] << ' ' << cnt << '\n';
    for(i=1;i<=n;i++)cout << id[i] << ' ';
    return 0;
}