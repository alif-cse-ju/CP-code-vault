#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int a[7],b[7],i,ans=0;
    for(i=0;i<7;i++)cin >> a[i];
    for(i=0;i<7;i++)cin >> b[i];
    for(i=0;i<7;i++)ans+=abs(a[i]-b[i]);
    cout << ans;
    return 0;
}
//