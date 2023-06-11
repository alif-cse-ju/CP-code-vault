#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;
const int sz = 5e3+5;
int a[sz];
ll dp[sz][2],_or[sz][sz];
void Compute(int grpNo,int l,int r,int optl,int optr)
{
    if(l > r)return;
    int m=(l+r) >> 1;
    int opt;
    ll &ans=dp[m][grpNo];
    ans=LLONG_MIN;
    for(int i=optl;i<=min(m,optr);i++)
    {
        ll tmp=dp[i-1][grpNo^1]+_or[i][m];
        if(tmp > ans)ans=tmp, opt=i;
    }
    Compute(grpNo,l,m-1,optl,opt), Compute(grpNo,m+1,r,opt,optr);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int k,n;cin >> n >> k;
        for(int i=1;i<=n;i++)cin >> a[i];
        for(int i=1;i<=n;i++)
        {
            _or[i][i]=a[i], dp[i][0]=LLONG_MIN;
            for(int j=i+1;j<=n;j++)_or[i][j]=(_or[i][j-1] | a[j]);
        }
        for(int i=1;i<=k;i++)Compute(i%2,1,n,1,n);
        cout << dp[n][k%2] << '\n';
    }
    return 0;
}