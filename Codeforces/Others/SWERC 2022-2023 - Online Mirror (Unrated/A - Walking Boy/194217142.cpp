#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mem(x,y) memset(x,y,sizeof(x))
#define ld long double
ll const MX = 1e6+6, lim = 1e6;
ll inf = 1e18;
int main()
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test, tc;
    cin>>test;
    for(tc=1; tc<=test; tc++)
    {
        ll i,j,k,s,d,r,m,n, f=0;
        vector<ll> vc;
        cin>>n;
        vc.pb(0);
        for(i=1; i<=n; i++) cin>>r, vc.pb(r);
        vc.pb(1440);
        sort(vc.begin(), vc.end());
        for(i=1; i<vc.size(); i++)
        {
            if(vc[i] - vc[i-1] >=120) f+= (vc[i] - vc[i-1]) / 120;
        }
        if(f>1)     cout<<"YES"<<endl;
        else        cout<<"NO"<<endl;
        //cout<<"Case "<<tc<<": ";
    }
}
    