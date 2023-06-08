#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
long long a[N],fact[N];
void PreCal()
    fact[0]=1;
    for(int i=1;i<N;i++)fact[i]=(fact[i-1]*i)%mod;
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
    if(r > n)return 0;
    return (fact[n]*BigMod(fact[r]*fact[n-r],mod-2))%mod;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,k,l,m,n,r,t,x;
    long long ans;
    PreCal();
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        for(i=1;i<=n;i++)cin >> a[i];
        sort(a+1,a+n+1);
        ans=0;
        for(i=1;i<=n;i++)
        {
            l=i;
            r=upper_bound(a+1,a+n+1,a[i]+k)-a;
            ans+=nCr(r-l-1,m-1);
            ans%=mod;
        }
        cout << ans << '\n';
    }
    return 0;
}