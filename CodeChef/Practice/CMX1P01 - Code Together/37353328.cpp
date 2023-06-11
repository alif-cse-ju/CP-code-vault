#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,j,k,l,lp,lbal1,lbal2,m,n,t,x;
    LL ans,cnt,luck[162],gldr[162];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        vector<int>grps[m+2];
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            grps[x].emplace_back(i);
        }
        for(i=1;i<=n;i++)scanf("%lld",&luck[i]);
        for(i=1;i<=m;i++)scanf("%lld",&gldr[i]);
        for(i=1;i<=m;i++)
        {
            l=grps[i].size();
            vector<LL>v;
            for(j=0;j<l;j++)
            {
                x=luck[grps[i][j]]%gldr[i];
                v.emplace_back(x);
            }
            if(v.size() == 1)
            {
                printf("%lld ",v[0]);
                continue;
            }
            l=v.size();
            vector<LL>v1,v2,bal1,bal2;
            for(j=0;j<l/2;j++)v1.emplace_back(v[j]);
            for(j=l/2;j<l;j++)v2.emplace_back(v[j]);
            lbal1=v1.size();
            lbal2=v2.size();
            lp=(1 << lbal1);
            for(j=1;j<lp;j++)
            {
                cnt=1;
                for(k=0;k<lbal1;k++)
                {
                    if((j >> k) & 1)cnt=(cnt*v1[k])%gldr[i];
                }
                bal1.emplace_back(cnt);
            }
            lp=(1 << lbal2);
            for(j=1;j<lp;j++)
            {
                cnt=1;
                for(k=0;k<lbal2;k++)
                {
                    if((j >> k) & 1)cnt=(cnt*v2[k])%gldr[i];
                }
                bal2.emplace_back(cnt);
            }
            ans=0;
            bal1.emplace_back(1);
            bal2.emplace_back(1);
            lbal1=bal1.size();
            for(j=0;j<lbal1;j++)
            {
                if(j == lbal1-1)bal2.pop_back();
                for(LL y : bal2)ans=max(ans,(bal1[j]*y)%gldr[i]);
            }
            printf("%lld ",ans);
        }
        printf("\n");
    }
    return 0;
}