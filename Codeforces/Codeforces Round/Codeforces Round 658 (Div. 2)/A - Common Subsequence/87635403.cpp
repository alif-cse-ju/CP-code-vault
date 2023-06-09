#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,j,m,n,t,a[1002],b[1002];
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=m;i++)cin >> b[i];
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(a[i] == b[j])
                {
                    cout << "YES\n" << "1 " << a[i] << '\n';
                    break;
                }
            }
            if(j <= m)break;
        }
        if(i > n)cout << "NO\n";
    }
    return 0;