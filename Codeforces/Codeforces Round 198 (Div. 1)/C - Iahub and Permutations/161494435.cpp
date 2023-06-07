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

const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;

const int sz = 2e3+5;

int a[sz];
bool visited[sz];
ll fact[sz],dp[sz][sz];

void PreCal()
{
    fact[0]=1;
    for(int i=1;i<sz;i++)fact[i]=(fact[i-1]*i)%mod;
}

ll DP(int n,int k)
{
    if(!k)return fact[n];
    if(k == 1)return (n*fact[n])%mod;

    ll &ans=dp[n][k];
    if(ans > -1)return ans;
    return ans=(n * DP(n,k-1)  +  (k-1) * DP(n+1, k-2))%mod;
    /// n * DP(n,k-1) --> this element is placed in a free cell
    /// (k-1) * DP(n+1, k-1) --> placed in ith index where i is still absent in A
    ///and so now i-can be placed anywhere and so n is incremented by 1
    ///and k is decremented by 2
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m=0,n;cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i] > 0)visited[a[i]]=1;
        else ++m;
    }
    int k=0; ///k-stores number of elements where (i is not in A  & a[i]=-1)
    for(int i=1;i<=n;i++)
    {
        if(!visited[i]  &&  a[i] == -1)++k;
    }
    m -= k;
    memset(dp,-1,sizeof(dp));
    PreCal();
    cout << DP(m, k);
    return 0;
}