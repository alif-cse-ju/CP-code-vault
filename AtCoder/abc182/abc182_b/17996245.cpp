#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n,mx=0,ans,cnt,a[102];
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=2;i<1001;i++)
    {
        cnt=0;
        for(j=1;j<=n;j++)cnt+=(a[j]%i == 0);
        if(cnt > mx)mx=cnt,ans=i;
    }
    cout << ans;
    return 0;
}
