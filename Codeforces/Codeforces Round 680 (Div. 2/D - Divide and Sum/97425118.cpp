#include<bits/stdc++.h>
 using namespace std;
 const int N=3e5+5;
const long long mod=998244353;
 long long a[N],fact[N];
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
 long long nCr(int n,int r)
{
    return fact[n]*BigMod(fact[r]*fact[n-r],mod-2)%mod;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n;
    long long L=0,R=0;
    cin >> n;
    n <<= 1;
    fact[0]=1;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        fact[i]=(fact[i-1]*i)%mod;
    }
    sort(a+1,a+n+1);
    n >>= 1;
    for(i=1;i<=n;i++)L+=a[i],R+=a[n+i];
    cout << ((R-L)%mod)*nCr(n << 1,n)%mod;
    return 0;
}