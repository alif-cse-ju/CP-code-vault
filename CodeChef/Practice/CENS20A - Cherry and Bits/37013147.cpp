#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int a[N+5][N+5],cnt[N+5][N+5];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,m,n,q,x1,x2,y1,y2;
    char s[N+2];
    cin >> n >> m;
    for(i=1;i<=n;i++)
    {
        cin >> s+1;
        for(j=1;j<=m;j++)a[i][j]=s[j]-'0';
    }
    cin >> q;
    while(q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        ++cnt[x1][y1],++cnt[x2+1][y2+1];
        --cnt[x1][y2+1],--cnt[x2+1][y1];
    }
    for(i=1;i<=m;i++)
    {
        for(j=2;j<=n;j++)cnt[j][i]+=cnt[j-1][i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=2;j<=m;j++)cnt[i][j]+=cnt[i][j-1];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)cout << (a[i][j]+cnt[i][j])%2;
        cout << '\n';
    }
    return 0;
}