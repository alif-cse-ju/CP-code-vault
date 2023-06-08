#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,t;
    long long u,v,x,y,ans,gcd;
    cin >> t;
    while(t--)
    {
        cin >> n;
        map<pair<long long,long long>,long long>cnt;
        while(n--)
        {
            cin >> x >> y >> u >> v;
            x-=u,y-=v;
            gcd=abs(__gcd(x,y));
            ++cnt[{x/gcd,y/gcd}];
        }
        ans=0;
        for(auto it : cnt)
        {
            x=it.first.first;
            y=it.first.second;
            u=it.second;
            v=cnt[{-x,-y}];
            ans+=(u*v);
        }
        cout << ans/2 << '\n';
    }
    return 0;