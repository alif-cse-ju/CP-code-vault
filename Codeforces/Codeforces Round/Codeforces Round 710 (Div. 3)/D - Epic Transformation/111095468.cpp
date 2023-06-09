#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);
const int M=2e5+5;
const int N=1e5+5;
const int mod=1e9+7;
int main()
    FAST();
    int i,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n;
        map<int,int>cnt;
        while(n--)
        {
            cin >> x;
            ++cnt[x];
        }
        priority_queue<int>pq;
        for(auto it : cnt)pq.emplace(it.second);
        while((int)pq.size() > 1)
        {
            x=pq.top(),pq.pop();
            y=pq.top(),pq.pop();
            --x,--y;
            if(x)pq.emplace(x);
            if(y)pq.emplace(y);
        }
        cout << (pq.empty() ? 0 : pq.top()) << '\n';
    }
    return 0;