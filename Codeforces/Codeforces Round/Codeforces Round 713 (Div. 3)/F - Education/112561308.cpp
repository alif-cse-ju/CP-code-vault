#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
long long a[N],b[N];
int main()
    FAST();
    int i,n,t;
    long long c,ans,cur,cnt,temp;
    cin >> t;
    while(t--)
    {
        cin >> n >> c;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<n;i++)cin >> b[i];
        ans=LLONG_MAX,cnt=cur=0;
        for(i=1;i<=n;i++)
        {
            if(cur >= c)ans=min(ans,cnt);
            else ans=min(ans,cnt+(c-cur+a[i]-1)/a[i]);
            if(i < n)
            {
                if(cur >= b[i])
                {
                    ++cnt;
                    cur-=b[i];
                }
                else
                {
                    temp=(b[i]-cur+a[i]-1)/a[i];
                    cur+=temp*a[i]-b[i];
                    cnt+=temp+1;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}