#include <bits/stdc++.h>   
#define HS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long 
#define pll pair<ll,ll>
#define pb push_back
#define M 100'000'0007
#define lc '\n'
using namespace std;
int main()
{
    HS
    ll t;
    cin>>t;
    while(t--)
    {
        ll a[27];
        memset(a,0,sizeof(a));
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll g=0;
        for(ll i=0;i<n;i++)
        {
            a[s[i]-'a'+1]++;
        }
        for(ll i=0;i<=26;i++)
        {
            g=__gcd(g,a[i]);
        }
        for(char c='a';c<='z';c++)
        {
            ll val=a[c-'a'+1]/g;
            for(ll i=0;i<val;i++)
            {
                cout<<c;
            }
        }
        cout<<lc;
    }
    return 0;
}