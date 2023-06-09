#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,j,m,n,x,y;
    cin >> n >> m >> x >> y;
    cout << x << ' ' << y << '\n';
    cout << 1 << ' ' << y << '\n';
    for(i=1;i<=n;i++)
    {
        if(i & 1)
        {
            for(j=1;j<=m;j++)
            {
                if(i == 1  &&  j == y)continue;
                else if(i == x  &&  j == y)continue;
                cout << i << ' ' << j << '\n';
            }
        }
        else
        {
            for(j=m;j>0;j--)
            {
                if(i == x  &&  j == y)continue;
                cout << i << ' ' << j << '\n';
            }
        }
    }
    return 0;