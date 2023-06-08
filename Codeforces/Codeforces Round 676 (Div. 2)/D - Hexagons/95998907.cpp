#include<bits/stdc++.h>
 using namespace std;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,t;
    long long ans,c[8],cnt1,cnt2,x,y;
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        for(i=1;i<7;i++)cin >> c[i];
        ans=LLONG_MAX;
        cnt2=y-x,cnt1=y-cnt2;
        ans=min(ans,(cnt1 < 0 ? c[4] : c[1])*abs(cnt1) + (cnt2 < 0 ? c[5] : c[2])*abs(cnt2));
        cnt2=x-y,cnt1=x-cnt2;
        ans=min(ans,(cnt1 < 0 ? c[4] : c[1])*abs(cnt1) + (cnt2 < 0 ? c[3] : c[6])*abs(cnt2));
        cnt2=x,cnt1=y;
        ans=min(ans,(cnt1 < 0 ? c[5] : c[2])*abs(cnt1) + (cnt2 < 0 ? c[3] : c[6])*abs(cnt2));
        cout << ans << '\n';
    }
    return 0;
}