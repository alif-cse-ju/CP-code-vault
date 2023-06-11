#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,k,n,t,x,y,z,cnt1,cnt2;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        deque<int>odd,even;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            if(x & 1)odd.emplace_back(i);
            else even.emplace_back(i);
        }
        odd.emplace_back(i);
        even.emplace_back(i);
        cnt1=y=z=0;
        while(!odd.empty())
        {
            x=odd.front();
            if(x-y > k)
            {
                if(y == z)
                {
                    cnt1=INT_MAX;
                    break;
                }
                else
                {
                    ++cnt1;
                    y=z;
                }
            }
            else
            {
                z=x;
                odd.pop_front();
            }
        }
        cnt2=y=z=0;
        while(!even.empty())
        {
            x=even.front();
            if(x-y > k)
            {
                if(y == z)
                {
                    cnt2=INT_MAX;
                    break;
                }
                else
                {
                    ++cnt2;
                    y=z;
                }
            }
            else
            {
                z=x;
                even.pop_front();
            }
        }
        x=min(cnt1,cnt2);
        if(x == INT_MAX)cout << "-1\n";
        else cout << x+1 << '\n';
    }
    return 0;
}