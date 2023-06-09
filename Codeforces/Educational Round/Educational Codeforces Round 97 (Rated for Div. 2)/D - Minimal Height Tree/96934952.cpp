#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],deg[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        deque<int>dq;
        dq.emplace_back(1);
        for(i=2;i<=n;i++)
        {
            if(a[i] > dq.back())
            {
                deg[a[i]]=deg[dq.front()]+1;
                dq.emplace_back(a[i]);
            }
            else
            {
                dq.pop_front();
                deg[a[i]]=deg[dq.front()]+1;
                dq.emplace_back(a[i]);
            }
        }
        ans=0;
        for(i=2;i<=n;i++)ans=max(ans,deg[i]);
        cout << ans << '\n';
    }
    return 0;