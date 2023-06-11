#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    string s;
    int i,j,l,n,t,q,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        map<string,bool>mp;
        vector<string>v[102];
        while(n--)
        {
            cin >> s;
            mp[s]=1;
            v[(int)s.size()].emplace_back(s);
        }
        while(q--)
        {
            cin >> s;
            if(mp.find(s) != mp.end())cout << s << '\n';
            else
            {
                l=x=s.size();
                for(string vs : v[l])
                {
                    x=0;
                    for(i=0;i<l;i++)
                    {
                        if(vs[i] != s[i])++x;
                    }
                    if(x == 1)
                    {
                        cout << vs << '\n';
                        x=0;break;
                    }
                }
                if(x)
                {
                    ++l;
                    for(string vs : v[l])
                    {
                        i=j=0;
                        while(i < l)
                        {
                            if(vs[i] == s[j])++i,++j;
                            else ++i;
                        }
                        if(j == l-1)
                        {
                            cout << vs << '\n';
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}