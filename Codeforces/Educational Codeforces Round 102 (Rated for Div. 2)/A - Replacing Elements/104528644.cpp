#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int d,i,n,t,a[102];
    cin >> t;
    while(t--)
    {
        cin >> n >> d;
        for(i=1;i<=n;i++)cin >> a[i];
        sort(a+1,a+n+1);
        if(a[n] <= d  ||  a[1]+a[2] <= d)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;