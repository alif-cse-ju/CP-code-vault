#include<bits/stdc++.h>

using namespace std;

const int N=3e5+5;
const int mod=1e9+7;

long long BigMod(long long val,long long pow,long long mod)
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long m,n;
    cin >> n >> m;
    cout << (BigMod(10,n,m*m)/m)%m;
    return 0;
}