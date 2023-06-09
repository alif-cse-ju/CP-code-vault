#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,n,q,r,t,x,y;
    long long sum;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        for(i=1;i<=n;i++)cin >> a[i];
        a[i]=sum=0;
        for(i=1;i<=n;i++)sum+=max(0,a[i]-a[i+1]);
        cout << sum << '\n';
        while(q--)
        {
            cin >> l >> r;
            x=a[l],y=a[r];
            sum-=max(0,a[l-1]-a[l]);
            sum-=max(0,a[l]-a[l+1]);
            a[l]=y;
            sum+=max(0,a[l-1]-a[l]);
            sum+=max(0,a[l]-a[l+1]);
            sum-=max(0,a[r-1]-a[r]);
            sum-=max(0,a[r]-a[r+1]);
            a[r]=x;
            sum+=max(0,a[r-1]-a[r]);
            sum+=max(0,a[r]-a[r+1]);
            cout << sum << '\n';
        }
    }
    return 0;
}