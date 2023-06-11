#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,l,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        priority_queue<int>pq;
        l=0;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            if(!x)
            {
                if(!l)l=i;
            }
            else
            {
                if(l)pq.emplace(i-l);
                l=0;
            }
        }
        if(pq.empty())cout << "No\n";
        else if(pq.size() == 1  &&  !(pq.top() & 1))cout << "No\n";
        else
        {
            x=pq.top();
            pq.pop();
            if(pq.empty()  ||  (x & 1  &&  pq.top() < (x+1)/2))cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}