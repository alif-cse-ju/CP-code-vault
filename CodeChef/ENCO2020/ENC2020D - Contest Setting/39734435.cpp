#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int n,q,a[N];
bool Check(int val)
{
    int l=1,r,cnt=1;
    for(r=2;r<=n;r++)
    {
        if(a[r]-a[l] >= val)++cnt,l=r;
    }
    return cnt >= q;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,m,r,ans;
    cin >> n >> q;
    for(i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    l=0,r=1e9;
    while(l <= r)
    {
        m=(l+r) >> 1;
        if(Check(m))ans=m,l=m+1;
        else r=m-1;
    }
    cout << ans;
    return 0;
}