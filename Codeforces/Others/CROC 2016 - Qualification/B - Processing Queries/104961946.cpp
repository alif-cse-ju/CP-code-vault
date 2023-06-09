#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int a[N],b[N];
long long ans[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,m,n;
    long long cnt;
    deque<int>dq;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> a[i] >> b[i],ans[i]=-1;
    ++m;
    i=2;
    cnt=a[1];
    dq.emplace_back(1);
    while(!dq.empty())
    {
        cnt+=b[dq.front()];
        ans[dq.front()]=cnt;
        while(i <= n)
        {
            if(a[i] < cnt)
            {
                if((int)dq.size() < m)dq.emplace_back(i);
                i++;
            }
            else break;
        }
        dq.pop_front();
        if(dq.empty()  &&  i <= n)
        {
            cnt=a[i];
            dq.emplace_back(i++);
        }
    }
    for(i=1;i<=n;i++)cout << ans[i] << ' ';
    return 0;
}