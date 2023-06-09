#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<pair<int,int> >v;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            v.emplace_back(x,i);
        }
        sort(v.begin(),v.end());
        if(v[0].first+v[1].first > v[n-1].first)cout << "-1\n";
        else
        {
            vector<int>ans;
            ans.emplace_back(v[0].second);
            ans.emplace_back(v[1].second);
            ans.emplace_back(v[n-1].second);
            sort(ans.begin(),ans.end());
            for(int it : ans)cout << it << ' ';
            cout << '\n';
        }
    }
    return 0;