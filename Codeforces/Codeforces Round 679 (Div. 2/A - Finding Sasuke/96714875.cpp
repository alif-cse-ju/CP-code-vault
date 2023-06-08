#include<bits/stdc++.h>
 using namespace std;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,a[102];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=n;i++)
        {
            if(i & 1)
            {
                if(a[i] > 0)cout << abs(a[i+1]) << ' ';
                else cout << -abs(a[i+1]) << ' ';
            }
            else
            {
                if(a[i] > 0)cout << -abs(a[i-1]) << ' ';
                else cout << abs(a[i-1]) << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}