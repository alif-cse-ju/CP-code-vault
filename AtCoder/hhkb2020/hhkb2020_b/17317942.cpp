#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N=105;
char s[N][N];

int main()
{
    FAST();
    int i,j,m,n,ans=0;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> s[i]+1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(s[i][j] == '.')
            {
                if(i < n)ans+=s[i+1][j] == '.';
                if(j < m)ans+=s[i][j+1] == '.';
            }
        }
    }
    cout << ans;
    return 0;
}
