#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int k,l,n,r,a[300005],cnt[300005];
bool Check(int len)
    int i;
    for(i=len;i<=n;i++)
    {
        if(cnt[i]-cnt[i-len] <= k)
        {
            l=i-len+1,r=i;
            return true;
        }
    }
    return false;
int main()
    FAST();
    int i,high,low,mid;
    cin >> n >> k;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        cnt[i]=cnt[i-1];
        if(a[i] == 0)++cnt[i];
    }
    low=1,high=n;
    while(low <= high)
    {
        mid=(low+high) >> 1;
        if(Check(mid))low=mid+1;
        else high=mid-1;
    }
    cout << r-l+(l > 0) << '\n';
    for(i=l;i<=r;i++)
    {
        if(a[i] == 0)a[i]=1;
    }
    for(i=1;i<=n;i++)cout << a[i] << ' ';
    return 0;
}