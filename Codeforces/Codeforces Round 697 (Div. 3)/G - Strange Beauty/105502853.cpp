#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int a[N],dp[N];
vector<int>divs[N];
void PreCal()
    int i,j;
    for(i=1;i<N;i++)
    {
        for(j=i;j<N;j+=i)divs[j].emplace_back(i);
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,mx;
    cin >> t;
    PreCal();
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        memset(dp,0,sizeof(dp));
        sort(a+1,a+n+1);
        mx=0;
        for(i=1;i<=n;i++)
        {
            for(int it : divs[a[i]])dp[a[i]]=max(dp[a[i]],dp[it]);
            mx=max(mx,++dp[a[i]]);
        }
        cout << n-mx << '\n';
    }
    return 0;
}