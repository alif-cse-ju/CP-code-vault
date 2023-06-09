#include<bits/stdc++.h>
using namespace std;
int color_cnt[102];
int main()
    int i,n,x;
    cin >> n;
    int a[n+2];
    for(i=0; i<n; i++)
    {
        cin >> x >> a[i];
        color_cnt[x]++;
    }
    int ans=0;
    for(i=0; i<n; i++)
    {
        ans+=color_cnt[a[i]];
    }
    cout << ans;
    return 0;