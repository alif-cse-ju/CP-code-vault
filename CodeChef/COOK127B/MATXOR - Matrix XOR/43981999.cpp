#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=4e6+5;
const int mod=1e9+7;
long long cnt[N];
int main()
{
    FAST();
    int t;
    long long i,k,m,n,ans,cntt;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        ans=0,cntt=m+n;
        for(i=2;i<=cntt/2ll+1;i++)
        {
            cnt[i]=min(i-1ll,min(m,n));
            if(cnt[i] & 1)ans=(ans ^ (k+i));
        }
        for(i=cntt;i>cntt/2ll+1;i--)
        {
            if(cnt[cntt-i+2] & 1)ans=(ans ^ (k+i));
        }
        cout << ans << '\n';
    }
    return 0;
}