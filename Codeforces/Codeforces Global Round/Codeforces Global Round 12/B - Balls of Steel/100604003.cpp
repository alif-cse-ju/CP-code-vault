#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int x[102],y[102];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,k,n,t,cnt;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)cin >> x[i] >> y[i];
        for(i=1;i<=n;i++)
        {
            cnt=0;
            for(j=1;j<=n;j++)cnt+=((abs(x[i]-x[j])+abs(y[i]-y[j])) <= k);
            if(cnt == n)break;
        }
        if(i <= n)cout << "1\n";
        else cout << "-1\n";
    }
    return 0;