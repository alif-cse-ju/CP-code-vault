#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x,y,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=0;i<n;i++)cin >> x >> y;
        ans=0;
        while(n > 2)
        {
            ans+=n;
            n >>= 1;
        }
        cout << ans << '\n';
    }
    return 0;
}