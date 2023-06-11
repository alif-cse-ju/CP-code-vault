#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    LL ans,distx,disty;
    int i,n,t,a[100005],b[100005];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=0;i<n;i++)cin >> a[i];
        for(i=0;i<n;i++)cin >> b[i];
        ans=distx=disty=0;
        for(i=0;i<n;i++)
        {
            if(distx == disty  &&  a[i] == b[i])ans+=a[i];
            distx+=a[i],disty+=b[i];
        }
        cout << ans << '\n';
    }
    return 0;
}