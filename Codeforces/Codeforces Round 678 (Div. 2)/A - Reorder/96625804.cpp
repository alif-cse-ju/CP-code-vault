#include<bits/stdc++.h>
 using namespace std;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int m,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        while(n--)
        {
            cin >> x;
            m-=x;
        }
        if(!m)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}