#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n;
        priority_queue<int>pq;
        while(n--)
        {
            cin >> x;
            pq.emplace(x);
        }
        while(pq.size() > 1)
        {
            x=pq.top(),pq.pop();
            y=pq.top(),pq.pop();
            --x,--y;
            if(x)pq.emplace(x);
            if(y)pq.emplace(y);
        }
        if(pq.size() == 1)cout << "T\n";
        else cout << "HL\n";
    }
    return 0;