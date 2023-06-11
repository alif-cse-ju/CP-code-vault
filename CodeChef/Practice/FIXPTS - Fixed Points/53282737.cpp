#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans=0;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            if(x <= i)ans += n-i+1;
        }
        cout << ans << '\n';
    }
    return 0;
}