#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    string s;
    int i,j,l,t,x,y,ans,cnt;
    cin >> t;
    while(t--)
    {
        cin >> s;
        l=s.size();
        vector<int>v[12];
        for(i=0;i<l;i++)v[s[i]-'0'].emplace_back(i);
        cnt=0;
        for(i=0;i<10;i++)cnt=max(cnt,(int)v[i].size());
        ans=l-cnt;
        for(i=0;i<10;i++)
        {
            if(v[i].empty())continue;
            for(j=0;j<10;j++)
            {
                if(i == j  ||  v[j].empty())continue;
                x=v[i][0],cnt=1;
                while(true)
                {
                    if(cnt & 1)
                    {
                        auto it=upper_bound(v[j].begin(),v[j].end(),x);
                        if(it == v[j].end())break;
                        ++cnt,x=*(it);
                    }
                    else
                    {
                        auto it=upper_bound(v[i].begin(),v[i].end(),x);
                        if(it == v[i].end())break;
                        ++cnt,x=*(it);
                    }
                }
                if(cnt & 1)--cnt;
                ans=min(ans,l-cnt);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}