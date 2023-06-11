#include<bits/stdc++.h>
using namespace std;
int grid[505][505];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,j,t,n,cnt;
    bool flag;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                cin >> grid[i][j];
            }
        }
        flag=0;
        for(i=1; i<=n; i++)
        {
            cnt=0;
            for(j=1; j<=n; j++)
            {
                if(grid[i][j] == 0)
                {
                    cnt++;
                }
            }
            if(cnt == 0)
            {
                cout << "NO\n";
                flag=1;
                break;
            }
        }
        if(flag == 0)
        {
            for(i=1; i<=n; i++)
            {
                cnt=0;
                for(j=1; j<=n; j++)
                {
                    if(grid[j][i] == 0)
                    {
                        cnt++;
                    }
                }
                if(cnt == 0)
                {
                    cout << "NO\n";
                    flag=1;
                    break;
                }
            }
        }
        if(flag == 0)
        {
            cout << "YES\n";
        }
    }
    return 0;
}