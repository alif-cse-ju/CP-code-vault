#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
bool mark[M];
vector<int>prime;
int n,a[M],dp[M][20],nxt[M],pos[M];
void Sieve()
    int i,j;
    prime.emplace_back(2);
    for(i=3;i<M;i+=2)
    {
        if(!mark[i])
        {
            prime.emplace_back(i);
            if(i < 1e3)
            {
                for(j=i*i;j<M;j+=(i << 1))mark[j]=1;
            }
        }
    }
void PreCal()
    int i,j;
    for(i=1;i<=n+1;i++)dp[i][0]=pos[i];
    for(j=1;j<20;j++)
    {
        for(i=1;i<=n+1;i++)dp[i][j]=dp[dp[i][j-1]][j-1];
    }
int FindAns(int l,int r)
    int i,ans=1;
    for(i=19;i>=0;i--)
    {
        if(dp[l][i] <= r)
        {
            l=dp[l][i];
            ans+=(1 << i);
        }
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,m,q,r,mn;
    cin >> n >> q;
    for(i=1;i<=n;i++)cin >> a[i];
    Sieve();
    pos[n+1]=n+1;
    for(int it : prime)nxt[it]=n+1;
    for(i=n;i;i--)
    {
        mn=n+1;
        for(int it : prime)
        {
            if(1ll*it*it > a[i])break;
            if(a[i]%it == 0)
            {
                while(a[i]%it == 0)a[i]/=it;
                mn=min(mn,nxt[it]),nxt[it]=i;
            }
        }
        if(a[i] > 1)mn=min(mn,nxt[a[i]]),nxt[a[i]]=i;
        pos[i]=min(pos[i+1],mn);
    }
    PreCal();
    while(q--)
    {
        cin >> l >> r;
        cout << FindAns(l,r) << '\n';
    }
    return 0;
}