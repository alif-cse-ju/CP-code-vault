#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[4],ans,i,t;
    cin >> t;
    while(t--)
    {
        ans=0;
        for(i=0;i<4;i++)cin >> a[i];
        ans=max(ans,(a[0] != a[1]) + (a[2] != a[3]));
        ans=max(ans,(a[0] != a[2]) + (a[1] != a[3]));
        ans=max(ans,(a[0] != a[3]) + (a[1] != a[2]));
        cout << ans << '\n';
    }
    return 0;
}