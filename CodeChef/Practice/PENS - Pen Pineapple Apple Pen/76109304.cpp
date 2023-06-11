#include<bits/stdc++.h>
using namespace std;
const int mx = (1 << 20);
char s[mx];
int ache[mx],ans[mx],nxt[mx],pos[20];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin >> t;
    while(t--)
    {
        int k,n;cin >> n >> k >> s+1;
        memset(ache,0,sizeof(ache));
        memset(pos,0,sizeof(pos));
        for(int i=1;i<=k;i++)
        {
            string ss;cin >> ss;
            int mask=0;
            for(char &c : ss)mask |= (1 << (c-'a'));
            ache[mask]=i;
        }
        for(int i=mx-1;i>=0;i--)
        {
            if(ache[i])continue;
            for(int j=19;j>=0;j--)
            {
                if(!((i >> j) & 1)  &&  ache[i ^ (1 << j)])
                {
                    ache[i] = ache[i ^ (1 << j)];
                    break;
                }
            }
        }
        for(int i=n;i;i--)
        {
            priority_queue<pair<int,int>>pq;
            pos[s[i]-'a']=i;
            for(int i=0;i<20;i++)
            {
                if(pos[i])pq.emplace(-pos[i],i);
            }
            int mask=0,koiJabo=n+1;
            while(!pq.empty())
            {
                auto [p,i]=pq.top(); pq.pop();
                mask |= (1 << i);
                if(!ache[mask])
                {
                    koiJabo=-p, mask=(mask ^ (1 << i));
                    break;
                }
            }
            ans[i]=ache[mask], nxt[i]=koiJabo;
        }
        for(int i=1;i<=n;i=nxt[i])
        {
            for(int j=i;j<nxt[i];j++)cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}