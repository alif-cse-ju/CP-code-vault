#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=998244353;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    stack<int>stk;
    int i,l,x,mx=0,cnt=1;
    vector<pair<int,int>>v;
    cin >> s;
    l=(int)s.size();
    for(i=0;i<l;i++)
    {
        if(s[i] == '(')stk.emplace(i);
        else
        {
            if(!stk.empty())
            {
                if(v.empty())v.emplace_back(stk.top(),i);
                else
                {
                    while(!v.empty()  && v.back().first > stk.top())v.pop_back();
                    if(!v.empty()  &&  v.back().second+1 == stk.top())
                    {
                        x=v.back().first;
                        v.pop_back();
                        v.emplace_back(x,i);
                    }
                    else v.emplace_back(stk.top(),i);
                }
                stk.pop();
            }
        }
    }
    for(auto it : v)
    {
        if(it.second-it.first+1 > mx)cnt=1,mx=it.second-it.first+1;
        else if(it.second-it.first+1 == mx)++cnt;
    }
    cout << mx << ' ' << cnt;
    return 0;
}