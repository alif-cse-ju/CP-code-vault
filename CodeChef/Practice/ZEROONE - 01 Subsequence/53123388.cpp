#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int i,n,s,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        priority_queue<int>even, odd;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            if(i & 1)odd.emplace(x);
            else even.emplace(-x);
        }
        ans=s=0, n/=2;
        while(n--)
        {
            cout << odd.top() << ' ';
            s += odd.top(), odd.pop();
            cout << -even.top() << ' ';
            ans += s*(-even.top()), even.pop();
        }
        if(!odd.empty())cout << odd.top();
        cout << '\n' << ans << '\n';
    }
    return 0;
}