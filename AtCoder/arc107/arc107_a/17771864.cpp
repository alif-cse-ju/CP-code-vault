#include<bits/stdc++.h>

using namespace std;

const long long mod=998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long a,b,c;
    cin >> a >> b >> c;
    a=((a*(a+1LL))/2LL)%mod;
    b=((b*(b+1LL))/2LL)%mod;
    c=((c*(c+1LL))/2LL)%mod;
    cout << (a*((b*c)%mod))%mod;
    return 0;
}