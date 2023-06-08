#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int Solve(string& s)
    int i,l,ans=0;
    stack<char>stk;
    l=(int)s.size();
    if(l & 1)
    {
        cout << "Impossible";
        exit(0);
    }
    for(i=0;i<l;i++)
    {
        if(s[i] == '('  ||  s[i] == '{'  ||  s[i] == '['  ||  s[i] == '<')stk.emplace(s[i]);
        else
        {
            if(stk.empty())
            {
                cout << "Impossible";
                exit(0);
            }
            if(s[i] == ')')s[i]='(';
            else if(s[i] == '}')s[i]='{';
            else if(s[i] == ']')s[i]='[';
            else s[i]='<';
            if(stk.top() != s[i])++ans;
            stk.pop();
        }
    }
    if(!stk.empty())
    {
        cout << "Impossible";
        exit(0);
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    cout << Solve(s);
    return 0;
}
//