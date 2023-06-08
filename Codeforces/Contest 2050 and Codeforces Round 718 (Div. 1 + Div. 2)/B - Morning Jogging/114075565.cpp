#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e2+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[M][M],ans[M][M],l[M],r[M];
int main()
    FAST();
    int i,j,m,n,pos,t;
    cin >> t;
    l[0]=1,a[0][1]=INT_MAX;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)
        {
            l[i]=1,r[i]=m;
            for(j=1;j<=m;j++)cin >> a[i][j];
            sort(a[i]+1,a[i]+m+1);
        }
        for(i=1;i<=m;i++)
        {
            pos=0;
            for(j=1;j<=n;j++)
            {
                if(a[pos][l[pos]] > a[j][l[j]])pos=j;
            }
            for(j=1;j<=n;j++)ans[j][i]=(j == pos ? a[j][l[j]++] : a[j][r[j]--]);
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)cout << ans[i][j] << ' ';
            cout << '\n';
        }
    }
    return 0;
}