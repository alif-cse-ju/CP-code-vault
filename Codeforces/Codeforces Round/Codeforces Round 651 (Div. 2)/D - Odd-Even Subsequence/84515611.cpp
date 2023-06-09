#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int k,n,a[200005];
bool Check(int val)
    int i,cnt=0;
    for(i=1;i<=n;i++)
    {
        if(cnt%2 == 0)
        {
            if(a[i] <= val)++cnt;
        }
        else ++cnt;
    }
    if(cnt >= k)return 1;
    cnt=0;
    for(i=1;i<=n;i++)
    {
        if(cnt%2 == 1)
        {
            if(a[i] <= val)++cnt;
        }
        else ++cnt;
    }
    if(cnt >= k)return 1;
    return 0;
int main()
    FAST();
    int i,ans,low,mid,high;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    low=1,high=1e9;
    while(low <= high)
    {
        mid=(low+high) >> 1;
        if(Check(mid))ans=mid,high=mid-1;
        else low=mid+1;
    }
    cout << ans;
    return 0;
}