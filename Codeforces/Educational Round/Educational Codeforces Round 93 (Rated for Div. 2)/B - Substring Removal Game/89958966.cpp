#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    string s;
    int i,l,t,cnt;
    cin >> t;
    while(t--)
    {
        cin >> s;
        l=s.size();
        vector<int>v;
        cnt=s[0]-'0';
        for(i=1;i<l;i++)
        {
            if(s[i] == '0')
            {
                if(cnt)v.emplace_back(cnt);
                cnt=0;
            }
            else ++cnt;
        }
        if(cnt)v.emplace_back(cnt);
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        cnt=0,l=v.size();
        for(i=0;i<l;i+=2)cnt+=v[i];
        cout << cnt << '\n';
    }
    return 0;