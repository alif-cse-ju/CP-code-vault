#include<bits/stdc++.h>
 using namespace std;
 int ans[102][102];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                ans[i][j]=0;
                if(i == j)ans[i][j]=1;
                else if(j == i+1)ans[i][j]=1;
                else if(i == n)ans[i][1]=1;
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)cout << ans[i][j] << ' ';
            cout << '\n';
        }
    }
    return 0;
}