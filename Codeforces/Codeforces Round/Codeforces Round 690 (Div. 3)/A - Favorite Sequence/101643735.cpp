#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        deque<int>dq;
        while(n--)
        {
            cin >> x;
            dq.emplace_back(x);
        }
        while(true)
        {
            if(!dq.empty())
            {
                cout << dq.front() << ' ';
                dq.pop_front();
            }
            else break;
            if(!dq.empty())
            {
                cout << dq.back() << ' ';
                dq.pop_back();
            }
            else break;
        }
        cout << '\n';
    }
    return 0;
}