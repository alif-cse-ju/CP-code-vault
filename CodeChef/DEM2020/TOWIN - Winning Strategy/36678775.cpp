#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    bool tgl;
    int i,n,t,x;
    long long sum1,sum2;
    cin >> t;
    while(t--)
    {
        cin >> n;
        tgl=false;
        sum1=sum2=0;
        priority_queue<int>pq;
        while(n--)
        {
            cin >> x;
            pq.emplace(x);
        }
        sum1=pq.top(),pq.pop();
        if(!pq.empty())sum2=pq.top(),pq.pop();
        while(!pq.empty())
        {
            if(!tgl)sum2+=pq.top();
            else sum1+=pq.top();
            pq.pop();
            tgl=!tgl;
        }
        if(sum1 > sum2)cout << "first\n";
        else if(sum1 < sum2)cout << "second\n";
        else cout << "draw\n";
    }
    return 0;
}