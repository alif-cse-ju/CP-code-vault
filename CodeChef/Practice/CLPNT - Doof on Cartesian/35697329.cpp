#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,n,t,q,x,y,ans,low,high,mid,a[200002];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        a[n+1]=INT_MAX;
        cin >> q;
        while(q--)
        {
            cin >> x >> y;
            ans=n+1,low=1,high=n;
            while(low <= high)
            {
                mid=(low+high) >> 1;
                if(x+y <= a[mid])
                {
                    ans=mid;
                    high=mid-1;
                }
                else low=mid+1;
            }
            if(x+y == a[ans])cout << "-1\n";
            else cout << ans-1 << '\n';
        }
    }
    return 0;
}