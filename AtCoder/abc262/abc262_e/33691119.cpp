#pragma GCC optimize("Ofast")

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
const int N=2e6+5;
const int mod=998244353;

int deg[M];
ll fact[M],invFact[M];

long long BigMod(long long val,long long pow)
{
    long long res = 1;
    val = val % mod;
    while(pow > 0)
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
    invFact[M-1]=BigMod(fact[M-1],mod-2);
    for(int i=M-2;i>=0;i--)invFact[i]=(invFact[i+1]*(i+1))%mod;
}

ll nCr(int n,int r)
{
    if(n < r)return 0;
    return (fact[n] * ((invFact[r]*invFact[n-r]) % mod))%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    int k,m,n;cin >> n >> m >> k;
    while(m--)
    {
        int x,y;cin >> x >> y;
        ++deg[x], ++deg[y];
    }
    ll ans=0;
    int even=0,odd=0;
    for(int i=1;i<=n;i++)
    {
        if(deg[i] & 1)++odd;
        else ++even;
    }
    for(int i=0;i<=min(k,odd);i+=2)
    {
        ans += (nCr(odd,i) * nCr(even,k-i))%mod;
        if(ans >= mod)ans -= mod;
    }
    cout << ans;
    return 0;
}
