#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,t,cur;
    long long k;
    bool mark[2005];
    cin >> t;
    while(t--)
    {
        cin >> k;
        if(k & 1)cout << "-1\n";
        else
        {
            cur=1;
            memset(mark,0,sizeof(mark));
            while(k)
            {
                for(i=1;(1LL << (i+1))-2 <= k;i++);
                cur+=i-1;
                mark[cur]=1;
                k-=(1LL << (i))-2;
            }
            mark[1]=1;
            cout << cur-1 << '\n';
            for(i=1;i<cur;i++)cout << mark[i] << ' ';
            cout << '\n';
        }
    }
    return 0;