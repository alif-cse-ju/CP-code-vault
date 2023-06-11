#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int k,n,a[N];
bool Check(int val)
{
    int l=1,r,cnt=1;
    for(r=2;r<=n;r++)
    {
        if(a[r]-a[l] >= val)l=r,++cnt;
    }
    return cnt >= k;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,m,r,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)cin >> a[i];
        if(k == 1)cout << "0\n";
        else
        {
            sort(a+1,a+n+1);
            l=1,r=a[n];
            while(l <= r)
            {
                m=(l+r) >> 1;
                if(Check(m))ans=m,l=m+1;
                else r=m-1;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}