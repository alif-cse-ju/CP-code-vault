#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int mod=1e9+7;
long long fact[N];
int a[N],cnt1[N],cnt2[N];
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
    return (fact[n]*BigMod(fact[r]*fact[n-r],mod-2))%mod;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,k,n,t;
    PreCal();
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)cnt1[i]=cnt2[i]=0;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            ++cnt1[a[i]];
        }
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);
        for(i=1;i<=k;i++)++cnt2[a[i]];
        cout << nCr(cnt1[a[k]],cnt2[a[k]]) << '\n';
    }
    return 0;
}