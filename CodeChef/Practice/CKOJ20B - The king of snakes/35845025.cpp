#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
LL k,n,a[100002];
LL Check(LL mid)
{
    LL x,ans=0;
    for(int i=1;i<=n;i++)
    {
        x=abs(mid-a[i]);
        if(k == 1)ans+=x;
        else if(k == 2)ans+=x*x;
        else ans+=x*x*x;
    }
    return ans;
}
int main()
{
    FAST();
    LL x,mn=LLONG_MAX;
    int i,low=0,mid,high=1e5,pos;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    while(low+5 < high)
    {
        mid=(low+high) >> 1;
        if(Check(mid) < Check(mid+1))high=mid;
        else low=mid+1;
    }
    for(i=low;i<=high;i++)
    {
        x=Check(i);
        if(x < mn)mn=x,pos=i;
    }
    cout << pos;
    return 0;
}