#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        deque<int>dq;
        for(i=0;i<n;i++)cin >> x, dq.emplace_back(x);
        sort(dq.begin(),dq.end());
        x=dq.front();
        ans=1ll*n*x;
        while(!dq.empty()  &&  dq.front() == x)dq.pop_front();
        ans += (int)dq.size();
        cout << ans << '\n';
    }
    return 0;
}