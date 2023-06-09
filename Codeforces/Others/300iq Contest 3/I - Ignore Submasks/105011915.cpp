#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=998244353;
bool mark[65];
long long fact[65];
void PreCal()
    fact[0]=1;
    for(int i=1;i<65;i++)fact[i]=(fact[i-1]*i)%mod;
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
long long nCr(int n,int r)
    return (fact[n]*BigMod(fact[r]*fact[n-r],mod-2))%mod;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    PreCal();
    long long i,j,k,n,a[102],ans=0,cnt1,cnt2,temp;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)
    {
        cnt1=cnt2=0;
        for(j=0;j<k;j++)
        {
            if(mark[j])++cnt1;
            else if((a[i] >> j) & 1)
            {
                mark[j]=1;
                ++cnt2;
            }
        }
        temp=BigMod(2,k-cnt1-cnt2);
        for(j=1;j<=cnt2;j++)
        {
            ans+=i*((temp*nCr(cnt2,j))%mod);
            ans%=mod;
        }
    }
    cout << ans;
    return 0;
}