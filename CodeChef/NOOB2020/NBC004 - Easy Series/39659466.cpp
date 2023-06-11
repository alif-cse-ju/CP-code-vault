#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    long long n,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans=(((n*n)%mod)*n)%mod;
        ans+=((1-n) * (1-n))%mod;
        ans%=mod;
        cout << ans << '\n';
    }
    return 0;
}