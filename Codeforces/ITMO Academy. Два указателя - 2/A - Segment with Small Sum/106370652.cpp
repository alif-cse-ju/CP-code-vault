#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,n,r,ans=0;
    long long x,sum=0;
    cin >> n >> x;
    for(i=1;i<=n;i++)cin >> a[i];
    for(l=r=1;r<=n;r++)
    {
        sum+=a[r];
        while(l < r  &&  sum > x)sum-=a[l++];
        if(sum <= x)ans=max(ans,r-l+1);
    }
    cout << ans;
    return 0;