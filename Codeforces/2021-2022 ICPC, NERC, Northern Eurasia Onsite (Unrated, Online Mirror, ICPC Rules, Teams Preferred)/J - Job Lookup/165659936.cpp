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
const int mod=1e9+7;

const int sz=205;

ll c[sz][sz],dp[sz][sz];
int n,par[sz],val[sz][sz];

ll DP(int l,int r)
{
    if(l > r)return 0;
    ll &ans=dp[l][r];
    if(ans > -1)return ans;
    ans=LLONG_MAX;
    for(int i=l;i<=r;i++)
    {
        ll tmp=DP(l,i-1) + DP(i+1,r);
        if(tmp < ans)ans=tmp, val[l][r]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(i < l  ||  i > r)ans += c[i][r]-c[i][l-1];
    }
    return ans;
}

void ParentKeBolo(int l,int r,int bap)
{
    if(l > r)return;
    par[val[l][r]]=bap;
    ParentKeBolo(l,val[l][r]-1,val[l][r]);
    ParentKeBolo(val[l][r]+1,r,val[l][r]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cin >> c[i][j], c[i][j] += c[i][j-1], dp[i][j]=-1;
    }
    ll tmp=DP(1,n);
    ParentKeBolo(1,n,0);
    for(int i=1;i<=n;i++)cout << par[i] << ' ';
    return 0;
}