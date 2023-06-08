#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long x,sum=0;
    int i,l,n,r,ans=INT_MAX;
    cin >> n >> x;
    for(i=1;i<=n;i++)cin >> a[i];
    for(l=r=1;r<=n;r++)
    {
        sum+=a[r];
        while(l < r  &&  sum-a[l] >= x)sum-=a[l++];
        if(sum >= x)ans=min(ans,r-l+1);
    }
    if(ans == INT_MAX)cout << "-1";
    else cout << ans;
    return 0;