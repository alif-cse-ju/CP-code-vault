#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int N=2e5+5;
const int mod=1e9+7;
int main()
    FAST();
    int i,n,t,x,cnt;
    long long a,b;
    cin >> t;
    while(t--)
    {
        cin >> n;
        priority_queue<long long>odd,even;
        for(i=0;i<n;i++)
        {
            cin >> x;
            if(x & 1)odd.emplace(x);
            else even.emplace(x);
        }
        a=b=cnt=0;
        while(!odd.empty() &&  !even.empty())
        {
            ++cnt;
            if(cnt & 1)
            {
                if(even.top() >= odd.top())
                {
                    a+=even.top();
                    even.pop();
                }
                else odd.pop();
            }
            else
            {
                if(even.top() <= odd.top())
                {
                    b+=odd.top();
                    odd.pop();
                }
                else even.pop();
            }
        }
        while(!even.empty())
        {
            ++cnt;
            if(cnt & 1)a+=even.top();
            even.pop();
        }
        while(!odd.empty())
        {
            ++cnt;
            if(!(cnt & 1))b+=odd.top();
            odd.pop();
        }
        if(a > b)cout << "Alice\n";
        else if(a < b)cout << "Bob\n";
        else cout << "Tie\n";
    }
    return 0;
}