#include<bits/stdc++.h>

using namespace std;

#define LL long long int
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

LL big_mod(LL val,LL pow,LL mod)
{
    LL res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)
        {
            res = (res*val) % mod;
        }
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}

LL fact[200005],mod=998244353;

LL Fun(LL n,LL x)
{
    return (fact[n]*big_mod((fact[x]*fact[n-x])%mod,mod-2,mod))%mod;
}

int main()
{
    FAST();
    LL i,k,m,n,ans=0;
    cin >> n >> m >> k;
    fact[0]=fact[1]=1;
    for(i=2;i<=n;i++)fact[i]=(fact[i-1]*i)%mod;
    for(i=0;i<=k;i++)ans=(ans+m*big_mod(m-1,n-i-1,mod)%mod*Fun(n-1,i)%mod)%mod;
    cout << ans;
    return 0;
}
