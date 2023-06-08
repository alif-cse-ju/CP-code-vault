#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int a,b,c,d,i,x;
    cin >> a >> b >> c >> d;
    deque<int>dq;
    x=min(a,b);
    a-=x,b-=x;
    if(a > 1)
    {
        cout << "NO";
        return 0;
    }
    for(i=0;i<x;i++)
    {
        dq.emplace_back(0);
        dq.emplace_back(1);
    }
    if(a == 1)
    {
        if(c  ||  d)
        {
            cout << "NO";
            return 0;
        }
        --a;
        dq.emplace_back(0);
    }
    if(b)
    {
        --b;
        dq.emplace_front(1);
    }
    x=min(b,c);
    b-=x,c-=x;
    if(b > 1)
    {
        cout << "NO";
        return 0;
    }
    for(i=0;i<x;i++)
    {
        dq.emplace_back(2);
        dq.emplace_back(1);
    }
    if(!c  &&  d  &&  !dq.empty()  &&  dq.back() != 2)
    {
        cout << "NO";
        return 0;
    }
    x=min(c,d);
    c-=x,d-=x;
    for(i=0;i<x;i++)
    {
        dq.emplace_back(2);
        dq.emplace_back(3);
    }
    if(c)
    {
        --c;
        dq.emplace_back(2);
    }
    if(c  &&  !dq.empty()  &&  dq.front() == 1)
    {
        --c;
        dq.emplace_front(2);
    }
    if(d > 1)
    {
        cout << "NO";
        return 0;
    }
    if(d)
    {
        if(dq.empty()  ||  dq.front() == 2)
        {
            --d;
            dq.emplace_front(3);
        }
    }
    if(a  ||  b  ||  c  ||  d)cout << "NO";
    else
    {
        cout << "YES\n";
        while(!dq.empty())
        {
            cout << dq.front() << ' ';
            dq.pop_front();
        }
    }
    return 0;
}