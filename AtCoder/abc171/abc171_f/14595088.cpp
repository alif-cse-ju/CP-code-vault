#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

LL fact[2000002];
const LL mod=1e9+7;

LL BigMod(LL val,LL pow)
{
    LL res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}

LL nCr(LL n,LL r)
{
    if(n < r)return 0;
    return fact[n]*BigMod(fact[r]*fact[n-r],mod-2)%mod;
}

int main()
{
    FAST();
    string s;
    fact[0]=1;
    LL i,k,l,ans=0;
    cin >> k >> s;
    l=(LL)s.size();
    for(i=1;i<=k+l;i++)fact[i]=(fact[i-1]*i)%mod;
    for(i=0;i<=k;i++)
    {
        ans+=nCr(k+l-i-1,l-1)*(BigMod(26,i)*BigMod(25,k-i)%mod)%mod;
        if(ans >= mod)ans-=mod;
    }
    cout << ans;
    return 0;
}
