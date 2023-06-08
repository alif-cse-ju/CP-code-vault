#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,m,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        ans=(m*n-(m%3)*(n%3))/3;
        m%=3, n%=3;
        if(m == 1  &&  n == 1)++ans;
        else ans += (m*n)/2;
        cout << ans << '\n';
    }
    return 0;