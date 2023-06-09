#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    string s;
    int i,l,t,ans,cnt;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        cnt=1;
        vector<int>v;
        for(i=1;i<l;i++)
        {
            if(s[i] == s[i-1])++cnt;
            else v.emplace_back(cnt),cnt=1;
        }
        v.emplace_back(cnt);
        if((int)v.size() == 1)cout << (cnt+2)/3 << '\n';
        else
        {
            ans=0;
            if(s[0] == s[l-1])
            {
                v[0]+=v.back();
                v.pop_back();
            }
            for(int x : v)ans+=x/3;
            cout << ans << '\n';
        }
    }
    return 0;