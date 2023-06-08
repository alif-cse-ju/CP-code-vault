#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,ans;
    long long m,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans=0,m=1;
        while(2*(m*m+m) < n)++m,++ans;
        cout << ans << '\n';
    }
    return 0;