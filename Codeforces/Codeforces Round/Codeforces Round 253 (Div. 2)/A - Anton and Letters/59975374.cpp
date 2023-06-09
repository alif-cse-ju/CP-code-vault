#include<bits/stdc++.h>
using namespace std;
bool mark[27];
int main()
    int i,l,ans=0;
    string s;
    getline(cin,s);
    l=s.size()-1;
    for(i=1; i<l; i++)
    {
        if(s[i] >= 'a'  &&  s[i] <= 'z')
        {
            if(!mark[s[i]-'a'])
            {
                ans++;
                mark[s[i]-'a']=1;
            }
        }
    }
    cout << ans;
    return 0;