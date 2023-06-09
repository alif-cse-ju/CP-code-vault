#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,a[55],ans;
    a[0]=1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        deque<int>dq;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            if(!a[i])
            {
                if(a[i-1])dq.emplace_back(0);
                ++dq.back();
            }
        }
        if(!a[1])dq.pop_front();
        if(!a[n] && !dq.empty())dq.pop_back();
        ans=0;
        while(!dq.empty())
        {
            ans+=dq.back();
            dq.pop_back();
        }
        cout << ans << '\n';
    }
    return 0;