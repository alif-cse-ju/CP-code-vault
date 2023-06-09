#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t;
    long long x,y,z,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        ans=0;
        deque<pair<long long,long long>>dq;
        for(i=0;i<n;i++)
        {
            cin >> y;
            dq.emplace_back(y,1);
        }
        while(!dq.empty())
        {
            y=dq.front().first;
            z=dq.front().second;
            if(y%x)break;
            ans+=y*z;
            dq.pop_front();
            dq.emplace_back(y/x,z*x);
        }
        while(!dq.empty())
        {
            y=dq.front().first;
            z=dq.front().second;
            dq.pop_front();
            ans+=y*z;
        }
        cout << ans << '\n';
    }
    return 0;
}