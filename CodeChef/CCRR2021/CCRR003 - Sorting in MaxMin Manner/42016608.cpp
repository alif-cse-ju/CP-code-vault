#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        deque<int>dq;
        for(i=0;i<n;i++)
        {
            cin >> x;
            dq.emplace_back(x);
        }
        while((int)dq.size() > 1)
        {
            cout << dq.back() << ' ';
            dq.pop_back();
            cout << dq.front() << ' ';
            dq.pop_front();
        }
        if(!dq.empty())cout << dq.front();
        cout << '\n';
    }
    return 0;
}