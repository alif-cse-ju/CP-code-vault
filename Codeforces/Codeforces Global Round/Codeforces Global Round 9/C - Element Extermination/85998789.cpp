#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,j,n,t,a[300005];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        if(a[n] == n)cout << "YES\n";
        else if(a[n] > a[1])cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;