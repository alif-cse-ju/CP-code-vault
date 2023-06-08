#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,x;
    ll ans,k,mx,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        vector<ll>v;
        for(i=0;i<n;i++)
        {
            cin >> x;
            y=1;
            while(x--)y *= 10;
            v.emplace_back(y);
        }
        ans=0, ++k;
        for(i=1;i<n  &&  k;i++)
        {
            mx=v[i]/v[i-1]-1;
            mx=min(mx,k);
            ans += mx*v[i-1], k-=mx;
        }
        ans += k*v[n-1];
        cout << ans << '\n';
    }
    return 0;