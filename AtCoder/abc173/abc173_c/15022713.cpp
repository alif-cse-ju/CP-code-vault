#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    string s[7];
    int i,j,k,m,n,ans=0,cnt,col,row;
    cin >> n >> m >> k;
    for(i=0;i<n;i++)cin >> s[i];
    for(row=0;row<(1 << n);row++)
    {
        for(col=0;col <(1 << m);col++)
        {
            cnt=0;
            for(i=0;i<n;i++)
            {
                if((row >> i) & 1)continue;
                for(j=0;j<m;j++)
                {
                    if(!((col >> j) & 1)  &&  s[i][j] == '#')++cnt;
                }
            }
            if(cnt == k)++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}
