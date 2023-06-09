#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
LL BigMod(LL val,LL pow,LL mod)
    LL res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
LL ModInverse(LL val,LL mod)
    return BigMod(val,mod-2,mod);
int main()
    FAST();
    int i,n;
    const LL mod=1e9+7;
    LL x,ans=1,cnt=0,fact[1005];
    fact[0]=fact[1]=1;
    for(i=2;i<=1000;i++)fact[i]=(fact[i-1]*i)%mod;
    cin >> n >> cnt;
    for(i=1;i<n;i++)
    {
        cin >> x;
        cnt+=x;
        x=(fact[cnt-1]*ModInverse(fact[x-1]*fact[cnt-x],mod))%mod;
        ans=(ans*x)%mod;
    }
    cout << ans;
    return 0;
}