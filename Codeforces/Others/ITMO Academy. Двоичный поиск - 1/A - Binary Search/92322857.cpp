#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,q,x,idx;
    cin >> n >> q;
    for(i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    while(q--)
    {
        cin >> x;
        if(x < a[1]  ||  x > a[n])cout << "NO\n";
        else
        {
            idx=lower_bound(a+1,a+n+1,x)-a;
            if(a[idx] == x)cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;