#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    int i,l,ans=0,cntS=0,cntT=0;
    cin >> l >> s >> t;
    for(i=0;i<l;i++)
    {
        cntS+=(s[i] == '1');
        cntT+=(t[i] == '1');
    }
    if(cntS != cntT)cout << "-1";
    else
    {
        vector<int>s0,t0;
        for(i=0;i<l;i++)
        {
            if(s[i] == '0')s0.emplace_back(i);
            if(t[i] == '0')t0.emplace_back(i);
        }
        l=(int)s0.size();
        for(i=0;i<l;i++)ans+=(s0[i] != t0[i]);
        cout << ans;
    }
    return 0;
}