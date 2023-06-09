#include<bits/stdc++.h>
using namespace std;
const int N=3e4+5;
int a[N],b[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,cnt;
    bool valid;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=n;i++)b[i]=a[i]-a[i-1];
        cnt=b[1];
        for(i=2;i<=n;i++)
        {
            if(b[i] < 0  &&  cnt+b[i] >= 0)
            {
                cnt+=b[i];
                b[i]=0;
            }
        }
        valid=1;
        for(i=1;i<=n;i++)valid&=(b[i] >= 0);
        if(valid)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;