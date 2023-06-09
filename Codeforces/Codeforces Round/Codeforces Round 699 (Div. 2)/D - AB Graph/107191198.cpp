#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int mod=1e9+7;
char s[N][N];
vector<int>mark[N][2];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool fuck;
    int i,j,k,m,n,t,x,y,z;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)cin >> s[i]+1;
        if(m & 1)
        {
            cout << "YES\n";
            for(i=0;i<=m;i++)cout << (i%2)+1 << ' ';
            cout << '\n';
        }
        else
        {
            fuck=0;
            for(i=2;i<=n  &&  !fuck;i++)
            {
                for(j=1;j<i;j++)
                {
                    if(s[i][j] == s[j][i])
                    {
                        fuck=1;
                        cout << "YES\n";
                        for(k=0;k<=m;k++)
                        {
                            if(k & 1)cout << j << ' ';
                            else cout << i << ' ';
                        }
                        cout << '\n';
                        break;
                    }
                }
            }
            if(!fuck)
            {
                for(i=1;i<=n;i++)
                {
                    mark[i][0].clear();
                    mark[i][1].clear();
                    for(j=1;j<=n;j++)
                    {
                        if(i == j)continue;
                        mark[i][s[i][j]-'a'].emplace_back(j);
                    }
                }
                x=y=z=0;
                for(i=1;i<=n && !x;i++)
                {
                    for(j=0;j<2 &&  !x;j++)
                    {
                        for(int it : mark[i][j])
                        {
                            if(!mark[it][j].empty())
                            {
                                x=i,y=it,z=mark[it][j][0];
                                break;
                            }
                        }
                    }
                }
                if(x)
                {
                    fuck=1;
                    cout << "YES\n";
                    if((m/2) & 1)
                    {
                        for(i=1;i<=m+1;i++)
                        {
                            if(i & 1)
                            {
                                if(i%4 == 1)cout << x << ' ';
                                else cout << z << ' ';
                            }
                            else cout << y << ' ';
                        }
                    }
                    else
                    {
                        for(i=1;i<=m+1;i++)
                        {
                            if(i & 1)cout << y << ' ';
                            else
                            {
                                if(i%4)cout << z << ' ';
                                else cout << x << ' ';
                            }
                        }
                    }
                    cout << '\n';
                }
            }
            if(!fuck)cout << "NO\n";
        }
    }
    return 0;
}
//