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
const int M=5e5+5;
const int N=2e6+5;
const int mod=1e9+7;
ll a[M],sum[M];
int dp[M],pos[M],segTree[4*M];
void Build(int nodeNum,int l,int r)
    segTree[nodeNum]=-N;
    if(l == r)return;
    int m=(l+r) >> 1;
    Build(2*nodeNum,l,m);
    Build(2*nodeNum+1,m+1,r);
void Update(int nodeNum,int start,int end,int id,int val)
    if(start == end)
    {
        segTree[nodeNum]=val;
        return;
    }
    int mid=(start+end) >> 1;
    if(id <= mid)Update(2*nodeNum,start,mid,id,val);
    else Update(2*nodeNum+1,mid+1,end,id,val);
    segTree[nodeNum]=max(segTree[2*nodeNum], segTree[2*nodeNum+1]);
}
 int Query(int nodeNum,int start,int end,int l,int r)
{
    if(start >= l  &&  end <= r)return segTree[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return Query(2*nodeNum,start,mid,l,r);
    if(l > mid)return Query(2*nodeNum+1,mid+1,end,l,r);
    return max(Query(2*nodeNum,start,mid,l,mid), Query(2*nodeNum+1,mid+1,end,mid+1,r));
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<pair<ll,int>>v;
        for(int i=1;i<=n;i++)cin >> a[i], sum[i]=sum[i-1]+a[i], v.emplace_back(sum[i],-i);
        Build(1,1,n);
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)pos[-v[i].second]=i+1;
        for(int i=1;i<=n;i++)
        {
            if(sum[i] > 0)
            {
                dp[i]=i;
                Update(1,1,n,pos[i],dp[i]-i);
                continue;
            }
            dp[i]=dp[i-1];
            if(a[i] > 0)++dp[i];
            else if(a[i] < 0)--dp[i];
            dp[i]=max(dp[i], Query(1,1,n,1,pos[i])+i);
            Update(1,1,n,pos[i],dp[i]-i);
        }
        cout << dp[n] << '\n';
    }
    return 0;
}