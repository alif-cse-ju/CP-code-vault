#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int a[N],cnt[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long ans=0;
    int i,k,l,n,r,dist=0;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    for(l=r=1;r<=n;r++)
    {
        ++cnt[a[r]];
        if(cnt[a[r]] == 1)++dist;
        while(l < r  &&  dist > k)
        {
            --cnt[a[l]];
            if(!cnt[a[l]])--dist;
            l++;
        }
        if(dist <= k)ans+=r-l+1;
    }
    cout << ans;
    return 0;