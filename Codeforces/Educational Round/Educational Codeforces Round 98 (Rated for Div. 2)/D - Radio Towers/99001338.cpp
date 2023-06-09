#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=998244353;
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
long long fib[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long i,n,x,y;
    cin >> n;
    fib[1]=1;
    for(i=2;i<=n;i++)fib[i]=(fib[i-1]+fib[i-2])%mod;
    x=fib[n];
    y=BigMod(2,n);
    cout << (x*BigMod(y,mod-2))%mod;
    return 0;