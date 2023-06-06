#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long a,b,x,y,ans=0;
    cin >> x >> y >> a >> b;
    while((__int128)x*a < y  &&  (__int128)x*a<=b)++ans,x*=a;
    ans+=max(0LL,y-1-x)/b;
    cout << ans;
    return 0;
}
