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

const int M=400+5;
const int N=1e6+5;
const int mod=998244353;

bool pairr[M][M];
ll dp[M][M],fact[M];

ll BigMod(ll val,ll pow)
{
    ll res = 1;
    val = val % mod;
    while(pow)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}

void PreCal()
{
    fact[0]=1;
    for(int i=1;i<M;i++)fact[i]=(fact[i-1]*i)%mod;
}

ll nCr(int n,int r)
{
    return (fact[n]*BigMod(fact[r]*fact[n-r],mod-2))%mod;
}

ll DP(int l,int r)
{
    if(l > r)return 1ll;
    if(l+1 == r)return pairr[l][r];
    ll &ans=dp[l][r];
    if(ans > -1)return ans;
    ans=0;
    int x,y;
    ll temp;
    for(int i=r;i>l;i-=2)
    {
        if(pairr[l][i])
        {
            x=(i-l-1)/2,y=(r-i)/2;
            temp=(DP(l+1,i-1)*DP(i+1,r))%mod;
            temp=(temp*nCr(x+y+1,y))%mod;
            ans+=temp;
            if(ans >= mod)ans-=mod;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n,x,y;
    PreCal();
    cin >> n >> m;
    while(m--)
    {
        cin >> x >> y;
        pairr[x][y]=pairr[y][x]=1;
    }
    memset(dp,-1,sizeof(dp));
    cout << DP(1,2*n);
    return 0;
}
