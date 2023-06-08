#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;
const int mod=1e9+7;
int a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,k,n,t,x,ans,cnt;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            a[i]+=a[i-1];
        }
        ans=n-1;
        for(i=1;i<n;i++)
        {
            cnt=i-1,k=i,x=a[i];
            for(j=i+1;j<=n;j++)
            {
                if(a[j]-a[k] < x)continue;
                else if(a[j]-a[k] == x)
                {
                    cnt+=j-k-1;
                    k=j;
                }
                else
                {
                    cnt=INT_MAX;
                    break;
                }
            }
            if(k != n)cnt=INT_MAX;
            ans=min(ans,cnt);
        }
        cout << ans << '\n';
    }
    return 0;
}