#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int q[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,t,x;
    long long ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans=0;
        for(i=1;i<=n;i++)cin >> q[i],ans+=q[i];
        for(i=1;i<=n;i++)
        {
            cin >> m;
            while(m--)
            {
                cin >> x;
                ans+=x-q[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
//