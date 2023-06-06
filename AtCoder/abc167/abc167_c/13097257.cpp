#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int a[12][12],cost[12];

int main()
{
    FAST();
    int i,j,k,m,n,x,ans=INT_MAX,check,cnt[12];
    cin >> n >> m >> x;
    for(i=0;i<n;i++)
    {
        cin >> cost[i];
        for(j=0;j<m;j++)cin >> a[i][j];
    }
    for(i=1;i<(1 << n);i++)
    {
        check=0;
        for(j=0;j<m;j++)cnt[j]=0;
        for(j=0;j<n;j++)
        {
            if((1 << j) & i)
            {
                check+=cost[j];
                for(k=0;k<m;k++)cnt[k]+=a[j][k];
            }
        }
        for(j=0;j<m;j++)
        {
            if(cnt[j] < x)break;
        }
        if(j == m)ans=min(ans,check);
    }
    if(ans == INT_MAX)cout << "-1";
    else cout << ans;
    return 0;
}
