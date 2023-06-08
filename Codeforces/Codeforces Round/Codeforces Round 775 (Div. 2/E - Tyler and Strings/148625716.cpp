#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=2e5+5;
const int mod=998244353;
ll fact[M],invFact[M];
int b[M],cumFreq[M],freq[M];
long long BigMod(long long val,long long pow)
    long long res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
void PreCal()
    int i;
    fact[0]=1, invFact[0]=BigMod(1,mod-2);
    for(i=1;i<M;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
        invFact[i]=BigMod(fact[i],mod-2);
    }
void Update(int i,bool add)
{
    while(i < M)
    {
        if(add)++cumFreq[i];
        else --cumFreq[i];
        i += (i & -i);
    }
}
 int Query(int i)
{
    int ans=0;
    while(i)ans += cumFreq[i], i -= (i & -i);
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int boro,i,m,n,x;
    ll ans,cal,tmp=1;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> x, ++freq[x], Update(x,1);
    for(i=1;i<=m;i++)cin >> b[i];
    PreCal();
    for(i=1;i<M;i++)
    {
        if(freq[i])tmp=(tmp * invFact[freq[i]])%mod;
    }
    ans=(fact[n]*tmp)%mod;
    for(i=1;i<=min(m,n);i++)
    {
        boro=(n-i+1) - Query(b[i]);
        cal=(1ll*boro*fact[n-i])%mod;
        ans=(ans-cal*tmp)%mod;
        if(!freq[b[i]])break;
        Update(b[i], 0);
        tmp=(tmp * fact[freq[b[i]]])%mod;
        tmp=(tmp * invFact[--freq[b[i]]])%mod;
    }
    if(i > min(m,n)  &&  n >= m)ans=(ans-(fact[n-m]*tmp))%mod;
    if(ans < 0)ans += mod;
    cout << ans;
    return 0;
}