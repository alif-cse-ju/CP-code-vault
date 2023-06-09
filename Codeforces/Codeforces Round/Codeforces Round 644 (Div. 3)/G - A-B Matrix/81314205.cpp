#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    char ans[55][55];
    int i,j,k,m,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> x >> y;
        if(n*x != m*y)
        {
            cout << "NO\n";
            continue;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)ans[i][j]='0';
        }
        k=0;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<x;j++)
            {
                ++k;
                k%=m;
                if(k == 0)k=m;
                ans[i][k]='1';
            }
        }
        cout << "YES\n";
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)cout << ans[i][j];
            cout << '\n';
        }
    }
    return 0;
}