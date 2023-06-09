#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,q,x,y;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    cin >> q;
    while(q--)
    {
        cin >> x >> y;
        x=lower_bound(a+1,a+n+1,x)-a;
        y=upper_bound(a+1,a+n+1,y)-a;
        cout<< y-x << ' ';
    }
    return 0;