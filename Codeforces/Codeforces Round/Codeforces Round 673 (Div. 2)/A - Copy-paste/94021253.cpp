#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,k,n,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=0;i<n;i++)cin >> a[i];
        sort(a,a+n);
        ans=0;
        for(i=1;i<n;i++)
        {
            a[i]=max(0,k-a[i]);
            ans+=a[i]/a[0];
        }
        cout << ans << '\n';
    }
    return 0;