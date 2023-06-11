#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int a[302][302],b[302][302],c[302][302],row[302],col[302];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,m1,m2,n1,n2,t;
    cin >> t;
    while(t--)
    {
        cin >> n1 >> m1;
        for(i=1;i<=n1;i++)
        {
            for(j=1;j<=m1;j++)cin >> a[i][j];
        }
        cin >> n2 >> m2;
        for(i=1;i<=n2;i++)
        {
            for(j=1;j<=m2;j++)cin >> b[i][j];
        }
        if(n1 != n2  ||  m1 != m2)cout << "Syntax error\n";
        else
        {
            for(i=1;i<=n1;i++)
            {
                for(j=1;j<=m1;j++)c[i][j]=a[i][j]+b[i][j];
            }
            for(i=1;i<=n1;i++)row[i]=INT_MAX;
            for(i=1;i<=m1;i++)col[i]=0;
            for(i=1;i<=n1;i++)
            {
                for(j=1;j<=m1;j++)
                {
                    row[i]=min(row[i],c[i][j]);
                    col[j]=max(col[j],c[i][j]);
                }
            }
            vector<int>v;
            for(i=1;i<=n1;i++)
            {
                for(j=1;j<=m1;j++)
                {
                    if(row[i] == c[i][j]  &&  col[j] == c[i][j])v.emplace_back(c[i][j]);
                }
            }
            if(v.empty())cout << "404 not found\n";
            else
            {
                for(int it : v)cout << it << ' ';
                cout << '\n';
            }
        }
    }
    return 0;
}