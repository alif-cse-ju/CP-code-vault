#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
long long a[N],b[N],c[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long m,sum;
    int i,la,lb,n,t,x,ans;
    cin >> t;
    while(t--)
    {
        la=lb=sum=0;
        cin >> n >> m;
        for(i=1;i<=n;i++)cin >> c[i];
        for(i=1;i<=n;i++)
        {
            cin >> x;
            sum+=c[i];
            if(x == 1)a[++la]=c[i];
            else b[++lb]=c[i];
        }
        if(sum < m)
        {
            cout << "-1\n";
            continue;
        }
        sort(a+1,a+la+1);
        sort(b+1,b+lb+1);
        reverse(a+1,a+la+1);
        reverse(b+1,b+lb+1);
        for(i=1;i<=la;i++)a[i]+=a[i-1];
        for(i=1;i<=lb;i++)b[i]+=b[i-1];
        ans=INT_MAX;
        for(i=0;i<=lb;i++)
        {
            auto it=lower_bound(a,a+la+1,m-b[i])-a;
            if(it <= la)ans=min(ans,(int)it+i*2);
        }
        cout << ans << '\n';
    }
    return 0;
}