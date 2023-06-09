#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,j,n,ans=0,cnt,a[100005];
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i];
    for(i=1;i<=30;i++)
    {
        cnt=0;
        for(j=0;j<n;j++)
        {
            if(a[j] > i)cnt=0;
            else
            {
                cnt+=a[j];
                ans=max(ans,cnt-i);
                if(cnt < 0)cnt=0;
            }
        }
    }
    cout << ans;
    return 0;