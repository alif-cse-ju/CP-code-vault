#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,t,x,y,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        map<int,int>mp;
        priority_queue<int>pq;
        while(n--)
        {
            cin >> x;
            ++mp[x];
        }
        for(auto it : mp)pq.emplace(it.second);
        ans=0;
        while(pq.size() > 1)
        {
            ++ans;
            x=pq.top(),pq.pop();
            y=pq.top(),pq.pop();
            --x,--y;
            if(x)pq.emplace(x);
            if(y)pq.emplace(y);
        }
        if(!pq.empty())ans+=pq.top();
        cout << ans << '\n';
    }
    return 0;
}