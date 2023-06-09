#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
const int N=3e5+5;
int last[N],mn[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x,y,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)last[i]=mn[i]=0;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            mn[x]=max(mn[x],i-last[x]);
            last[x]=i;
        }
        for(i=1;i<=n;i++)mn[i]=max(mn[i],n-last[i]+1);
        priority_queue<PII,vector<PII>,greater<PII>>pq;
        for(i=1;i<=n;i++)pq.emplace(mn[i],i);
        ans=INT_MAX,y=pq.top().first;
        for(i=1;i<=n;i++)
        {
            if(y > i)
            {
                if(ans == INT_MAX)cout << "-1 ";
                else cout << ans << ' ';
            }
            else
            {
                if(!pq.empty())ans=min(ans,pq.top().second);
                cout << ans << ' ';
                x=pq.top().first;
                while(!pq.empty()  &&  pq.top().first == x)pq.pop();
                if(!pq.empty())y=pq.top().first;
            }
        }
        cout << '\n';
    }
    return 0;
}