#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    char s[102][1002];
    int i,j,m,n,t,x,y,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> x >> y;
        for(i=1;i<=n;i++)cin >> s[i]+1;
        ans=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(s[i][j] == '.')
                {
                    if(j < m  &&  s[i][j+1] == '.')
                    {
                        ans+=min(2*x,y);
                        s[i][j+1]='*';
                    }
                    else ans+=x;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;