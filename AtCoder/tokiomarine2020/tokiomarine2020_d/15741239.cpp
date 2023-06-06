#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int n;
LL val[1000002],weight[1000002],dp[100002][1025];

int main()
{
    FAST();
    int i,j,k,l,q,x;
    LL w,ans,cur,check;
    cin >> n;
    l=min(1023,n);
    for(i=1;i<=n;i++)cin >> val[i] >> weight[i];
    for(i=1;i<=1e5;i++)
    {
        for(j=1;j<=l;j++)
        {
            if(weight[j] <= i)dp[i][j]=max(dp[i][j/2],val[j]+dp[i-weight[j]][j/2]);
            else dp[i][j]=dp[i][j/2];
        }
    }
    cin >> q;
    while(q--)
    {
        cin >> x >> w;
        if(x <= l)cout << dp[w][x] << '\n';
        else
        {
            vector<int>v;
            while(x > l)v.emplace_back(x),x/=2;
            ans=dp[w][x],k=1 << (int)v.size();
            for(i=1;i<k;i++)
            {
                cur=check=0;
                for(j=0;j<v.size();j++)
                {
                    if((i >> j) & 1)cur+=val[v[j]],check+=weight[v[j]];
                }
                if(check <= w)
                {
                    cur+=dp[w-check][x];
                    ans=max(ans,cur);
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
