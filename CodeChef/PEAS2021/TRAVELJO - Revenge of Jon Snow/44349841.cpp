#include<bits/stdc++.h>
using namespace std;
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
void Solve()
{
    long long a,b,l,m,n,r,ans=0,lcm,sum;
    cin >> n >> a >> b;
    l=1,r=n*max(a,b),lcm=(a*b)/__gcd(a,b);
    while(l <= r)
    {
        m=(l+r) >> 1ll;
        sum=m/a+m/b-m/lcm;
        if(sum < n)l=m+1ll;
        else ans=m,r=m-1ll;
    }
    cout << ans%mod << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)Solve();
    return 0;
}
//1316