#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[N],cnt[32];
int main()
{
    FAST();
    int i,j,n,t,q,x,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        ans=0;
        memset(cnt,0,sizeof(cnt));
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            ans |= a[i];
            for(j=0;j<31;j++)
            {
                if((a[i] >> j) & 1)++cnt[j];
            }
        }
        cout << ans << '\n';
        while(q--)
        {
            cin >> i >> x;
            for(j=0;j<31;j++)
            {
                if((a[i] >> j) & 1)--cnt[j];
            }
            a[i]=x;
            ans=0;
            for(j=0;j<31;j++)
            {
                if((a[i] >> j) & 1)++cnt[j];
                if(cnt[j])ans+=(1 << j);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}