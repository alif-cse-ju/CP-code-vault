#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int k,n,cnt[10][200002];
int Check(int len)
{
    int i,j,l,x,ans=INT_MAX,check;
    for(i=len;i<=n;i++)
    {
        for(j=0;j<k;j++)
        {
            check=0;
            for(l=0;l<k;l++)
            {
                x=abs(j-l);
                check+=min(x,k-x)*(cnt[l][i]-cnt[l][i-len]);
            }
            ans=min(ans,check);
        }
    }
    return ans;
}
int main()
{
    FAST();
    int i,j,l,m,r,ans=0,mid,a[200002];
    cin >> n >> m >> k;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        a[i]%=k;cnt[a[i]][i]=1;
    }
    for(i=0;i<k;i++)
    {
        for(j=2;j<=n;j++)cnt[i][j]+=cnt[i][j-1];
    }
    l=1,r=n;
    while(l <= r)
    {
        mid=(l+r) >> 1;
        if(Check(mid) <= m)ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout << ans << '\n';
    return 0;
}