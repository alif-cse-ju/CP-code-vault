#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int mod=998244353;

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

map<ll,ll>dp;

ll Solve(ll n)
{
    if(n < 5)return n;
    if(dp.find(n) != dp.end())return dp[n];
    if(__builtin_popcountll(n) == 1)return dp[n]=BigMod(2,n/2);
    return dp[n]=(Solve((n+1)/2) * Solve(n/2))%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    cout << Solve(n);
    return 0;
}