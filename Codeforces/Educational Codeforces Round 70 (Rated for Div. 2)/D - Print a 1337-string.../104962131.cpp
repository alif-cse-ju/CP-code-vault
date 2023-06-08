#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
long long Solve(long long n)
    for(long long i=sqrt(n); ;i++)
    {
        if((i*(i+1)) > n)return i-1;
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,t;
    long long n,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 1)
        {
            cout << "1337\n";
            continue;
        }
        deque<int>dq;
        while(n > 1)
        {
            x=Solve(n);
            dq.emplace_back(x);
            n-=(x*(x+1));
        }
        cout << "13";
        for(i=1;!dq.empty();i++)
        {
            cout << '3';
            if(i == n)cout << '7';
            if(dq.back() == i)
            {
                while(!dq.empty()  &&  dq.back() == i)
                {
                    cout << "77";
                    dq.pop_back();
                }
            }
        }
        cout << '\n';
    }
    return 0;
}