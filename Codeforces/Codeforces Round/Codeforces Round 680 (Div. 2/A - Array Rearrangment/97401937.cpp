#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    bool valid;
    int i,n,t,x,a[55],b[55];
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=n;i++)cin >> b[i];
        valid=1;
        for(i=1;i<=n;i++)valid &= (a[i]+b[n-i+1] <= x);
        if(valid)cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;