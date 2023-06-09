#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    bool flag;
    int i,j,m,n,t,x,a[305][305];
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)cin >> a[i][j];
        }
        flag=true;
        for(i=1;i<=n  &&  flag;i++)
        {
            for(j=1;j<=m;j++)
            {
                x=0;
                if(i > 1)++x;
                if(i < n)++x;
                if(j > 1)++x;
                if(j < m)++x;
                if(x < a[i][j])
                {
                    flag=false;
                    break;
                }
                a[i][j]=x;
            }
        }
        if(!flag)cout << "NO\n";
        else
        {
            cout << "YES\n";
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=m;j++)cout <<  a[i][j] << ' ';
                cout << '\n';
            }
        }
    }
    return 0;
}