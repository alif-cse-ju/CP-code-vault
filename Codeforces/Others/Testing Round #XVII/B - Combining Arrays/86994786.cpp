#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n,x;
    deque<int>a,b,ans;
    cin >> n;
    for(i=0;i<n;i++)cin >> x,a.emplace_back(x);
    for(i=0;i<n;i++)cin >> x,b.emplace_back(x);
    while(!a.empty()  &&  !b.empty())
    {
        if(a.front() < b.front())
        {
            ans.emplace_back(a.front());
            a.pop_front();
        }
        else
        {
            ans.emplace_back(b.front());
            b.pop_front();
        }
    }
    while(!a.empty())
    {
        ans.emplace_back(a.front());
        a.pop_front();
    }
    while(!b.empty())
    {
        ans.emplace_back(b.front());
        b.pop_front();
    }
    while(!ans.empty())
    {
        cout << ans.front() << ' ';
        ans.pop_front();
    }
    return 0;
}