#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    long long a,b,c,p;
    cin >> t;
    while(t--)
    {
        cin >> p >> a >> b >> c;
        a=(p%a ? a-p%a : 0);
        b=(p%b ? b-p%b : 0);
        c=(p%c ? c-p%c : 0);
        cout << min({a,b,c}) << '\n';
    }
    return 0;