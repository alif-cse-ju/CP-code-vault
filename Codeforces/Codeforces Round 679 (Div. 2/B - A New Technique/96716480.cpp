#include<bits/stdc++.h>
 using namespace std;
 const int N=505;
int ans[N][N];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,m,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        map<int,int>row,col;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cin >> x;
                col[x]=j;
            }
        }
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin >> x;
                row[x]=j;
            }
        }
        for(i=1;i<=m*n;i++)ans[row[i]][col[i]]=i;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)cout << ans[i][j] << ' ';
            cout << '\n';
        }
    }
    return 0;
}