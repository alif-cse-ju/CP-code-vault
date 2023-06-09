#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],frnd[N],me[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        frnd[0]=1,me[1]=frnd[1]=a[1];
        for(i=2;i<=n;i++)
        {
            frnd[i]=me[i-1]+a[i];
            frnd[i]=min(frnd[i],me[i-2]+a[i]+a[i-1]);
            me[i]=min(frnd[i-1],frnd[i-2]);
        }
        cout << min(me[n],frnd[n]) << '\n';
    }
    return 0;