#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &x:a) cin >> x;
    ll ans = a[0]/k;
    ll t = a[0] - ans*k;
    for (int i = 1; i < n ; ++i)
    {
        ll T = t + a[i];
        ll p = T/k;
        if(!p && t != 0)
        {
            ans++;
            t = 0;
            continue;
        }
        ans+=p;
        t = T - p*k;
    }
    if(t!=0) ans++;
    cout << ans << "\n";
    return 0;