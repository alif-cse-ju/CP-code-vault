#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int a[1002][1002];
int main()
{
    FAST();
    int i,j,n,t,x;
    cin >> t;
    while(t--)
    {
        x=0;
        cin >> n;
        if(n & 1)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)cout << ++x << ' ';
                cout << '\n';
            }
        }
        else
        {
            for(i=1;i<=n;i++)
            {
                if(i & 1)
                {
                    for(j=1;j<=n;j++)a[i][j]=++x;
                }
                else
                {
                    for(j=n;j>0;j--)a[i][j]=++x;
                }
            }
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)cout << a[i][j] << ' ';
                cout << '\n';
            }
        }
    }
    return 0;
}