#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
int mark[5][5];
void change(int x,int y)
    mark[x][y]=(mark[x][y]+1)%2;
    if(x-1 > 0)
    {
        mark[x-1][y]=(mark[x-1][y]+1)%2;
    }
    if(y-1 > 0)
    {
        mark[x][y-1]=(mark[x][y-1]+1)%2;
    }
    if(x+1 < 4)
    {
        mark[x+1][y]=(mark[x+1][y]+1)%2;
    }
    if(y+1 < 4)
    {
        mark[x][y+1]=(mark[x][y+1]+1)%2;
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int a[5][5],i,j;
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            mark[i][j]=1;
        }
    }
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            cin >> a[i][j];
            if(a[i][j] & 1)
            {
                change(i,j);
            }
        }
    }
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            cout << mark[i][j];
        }
        cout << '\n';
    }
    return 0;
}