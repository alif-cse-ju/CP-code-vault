#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok;
    int l,n,t;
    string s,ss;
    cin >> t;
    while(t--)
    {
        ok=0;
        cin >> n;
        set<string>st,voda;
        while(n--)
        {
            cin >> s;
            l=(int)s.size();
            ss=s, reverse(ss.begin(),ss.end());
            if(s[0] == s[l-1]  ||  st.find(ss) != st.end()  ||  (l == 2  &&  voda.find(ss) != voda.end()))ok=1;
            else if(l > 2)
            {
                ss=s, reverse(ss.begin(),ss.end()), ss.pop_back();
                if(st.find(ss) != st.end())ok=1;
                else ss=s, ss.pop_back(), voda.insert(ss);
            }
            st.insert(s);
        }
        if(ok)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;