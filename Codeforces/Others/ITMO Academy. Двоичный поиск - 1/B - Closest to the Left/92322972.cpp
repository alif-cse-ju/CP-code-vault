#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,q,x;
    cin >> n >> q;
    for(i=1;i<=n;i++)cin >> a[i];
    while(q--)
    {
        cin >> x;
        cout << upper_bound(a+1,a+n+1,x)-a-1 << "\n";
    }
    return 0;