#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    bool val;
    int a,b,c,d,m,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        val=false;
        while(n--)
        {
            cin >> a >> b >> c >> d;
            if(b == c)val |= 1;
        }
        if(m & 1)cout << "NO\n";
        else
        {
            if(val)cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;