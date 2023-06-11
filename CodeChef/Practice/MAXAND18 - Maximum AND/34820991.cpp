#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,j,k,n,t;
    LL x,ans,pre[32],sum[32];
    for(i=0;i<31;i++)pre[i]=(1LL << i);
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        memset(sum,0,sizeof(sum));
        for(i=0;i<n;i++)
        {
            cin >> x;
            for(j=0;j<31;j++)
            {
                if((x >> j) & 1LL)sum[j]+=pre[j];
            }
        }
        ans=0;
        priority_queue<pair<LL,int> >pq;
        for(i=0;i<31;i++)pq.emplace(sum[i],-i);
        while(k--)
        {
            i=-pq.top().second;pq.pop();
            ans |= (1LL << i);
        }
        cout << ans << '\n';
    }
    return 0;
}