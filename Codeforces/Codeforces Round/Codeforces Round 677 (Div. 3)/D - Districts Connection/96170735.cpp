#include<bits/stdc++.h>
using namespace std;
vector<int>v[5005];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x,cnt,idx;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cnt=0;
        map<int,int>mp;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            if(mp.find(x) == mp.end())mp[x]=idx=++cnt;
            else idx=mp[x];
            v[idx].emplace_back(i);
        }
        if(cnt == 1)cout << "NO\n";
        else
        {
            cout << "YES\n";
            for(i=2;i<=cnt;i++)
            {
                for(int it : v[i])cout << v[1][0] << ' ' << it << '\n';
            }
            for(i=1;i<v[1].size();i++)cout << v[2][0] << ' ' << v[1][i] << '\n';
        }
        for(i=1;i<=cnt;i++)v[i].clear();
    }
    return 0;