#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
const int mod=1e9+7;

int a[N],b[N],cnt[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,x,y;
    bool flag;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i],++cnt[a[i]];
    for(i=1;i<=n;i++)cin >> b[i],++cnt[b[i]];
    for(i=1;i<=n;i++)
    {
        if(cnt[i] > n)
        {
            cout << "No";
            return 0;
        }
    }
    deque<int>dq;
    for(i=1;i<=n;i++)
    {
        if(a[i] == b[i])dq.emplace_back(i);
    }
    while((int)dq.size() > 1)
    {
        x=dq.front();
        y=dq.back();
        if(b[x] == b[y])break;
        swap(b[x],b[y]);
        dq.pop_back();
        dq.pop_front();
    }
    while(!dq.empty())
    {
        flag=false;
        for(i=1;i<=n  &&  !dq.empty();i++)
        {
            if(a[dq.front()] != b[i]  &&  b[dq.front()] != a[i])
            {
                swap(b[i],b[dq.front()]);
                dq.pop_front();
                flag=1;
            }
        }
        if(!flag)break;
    }
    if(!dq.empty())cout << "No";
    else
    {
        cout << "Yes\n";
        for(i=1;i<=n;i++)cout << b[i] << ' ';
    }
    return 0;
}