#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int k,l,t;
    cin >> t;
    while(t--)
    {
        cin >> l >> k >> s;
        deque<char>dq;
        for(char c : s)dq.emplace_back(c);
        while(k  &&  dq.front() == dq.back())
        {
            --k;
            dq.pop_back();
            dq.pop_front();
        }
        if(k  ||  dq.empty())cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;