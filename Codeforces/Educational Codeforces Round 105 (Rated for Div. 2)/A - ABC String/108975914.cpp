#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    bool flag;
    int t,cntA,cntB,cntC;
    cin >> t;
    while(t--)
    {
        cin >> s;
        flag=1;
        cntA=cntB=cntC=0;
        for(char c : s)
        {
            cntA+=(c == 'A');
            cntB+=(c == 'B');
            cntC+=(c == 'C');
        }
        stack<char>stk;
        if(cntA == cntB+cntC)
        {
            if(s[0] == 'A')
            {
                for(char c : s)
                {
                    if(c == 'A')stk.emplace(c);
                    else
                    {
                        if(stk.empty())
                        {
                            flag=0;
                            break;
                        }
                        stk.pop();
                    }
                }
            }
            else
            {
                for(char c : s)
                {
                    if(c == 'A')
                    {
                        if(stk.empty())
                        {
                            flag=0;
                            break;
                        }
                        stk.pop();
                    }
                    else stk.emplace(c);
                }
            }
        }
        else if(cntB == cntA+cntC)
        {
            if(s[0] == 'B')
            {
                for(char c : s)
                {
                    if(c == 'B')stk.emplace(c);
                    else
                    {
                        if(stk.empty())
                        {
                            flag=0;
                            break;
                        }
                        stk.pop();
                    }
                }
            }
            else
            {
                for(char c : s)
                {
                    if(c == 'B')
                    {
                        if(stk.empty())
                        {
                            flag=0;
                            break;
                        }
                        stk.pop();
                    }
                    else stk.emplace(c);
                }
            }
        }
        else if(cntC == cntA+cntB)
        {
            if(s[0] == 'C')
            {
                for(char c : s)
                {
                    if(c == 'C')stk.emplace(c);
                    else
                    {
                        if(stk.empty())
                        {
                            flag=0;
                            break;
                        }
                        stk.pop();
                    }
                }
            }
            else
            {
                for(char c : s)
                {
                    if(c == 'C')
                    {
                        if(stk.empty())
                        {
                            flag=0;
                            break;
                        }
                        stk.pop();
                    }
                    else stk.emplace(c);
                }
            }
        }
        else flag=0;
        if(flag)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
//