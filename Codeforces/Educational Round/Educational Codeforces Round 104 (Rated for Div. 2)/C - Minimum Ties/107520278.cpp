#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n & 1)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n-i;j++)
                {
                    if(j <= n/2)cout << 1 << ' ';
                    else cout << -1 << ' ';
                }
            }
        }
        else
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n-i;j++)
                {
                    if(j <= n/2-1)cout << 1 << ' ';
                    else if(j == n/2)cout << 0 << ' ';
                    else cout << -1 << ' ';
                }
            }
        }
        cout << '\n';
    }
    return 0;
}
//