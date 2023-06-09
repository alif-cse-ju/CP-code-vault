#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    LL ans=0,a[102][102],mx;
    int i,j,k,m,n,chords[100002];
    cin >> n >> m;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)cin >> a[i][j];
    }
    for(i=1;i<=n;i++)cin >> chords[i];
    if(n < 3)
    {
        cout << "0";
        return 0;
    }
    for(k=1;k<=m;k++)
    {
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=m;j++)a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        }
    }
    for(i=2;i<=n;i++)ans+=a[chords[i-1]][chords[i]];
    mx=max(a[chords[1]][chords[2]],a[chords[n-1]][chords[n]]);
    for(i=2;i<n;i++)mx=max(mx,a[chords[i-1]][chords[i]]+a[chords[i]][chords[i+1]]-a[chords[i-1]][chords[i+1]]);
    if(mx > 0)ans-=mx;
    cout << ans;
    return 0;