#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int N=2e5+5;
const int mod=1e9+7;
int ans[N];
int main()
    FAST();
    int i,j,n,t,x,y,z;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<pair<pair<int,int>,int>>v;
        for(i=1;i<=n;i++)
        {
            ans[i]=-1;
            cin >> x >> y;
            v.push_back({{min(x,y),max(x,y)},i});
        }
        sort(v.begin(),v.end());
        j=0,y=v[0].first.second,z=v[0].second;
        for(i=1;i<n;i++)
        {
            x=v[i].first.first;
            while(v[j].first.first < x)
            {
                if(v[j].first.second < y)z=v[j].second,y=v[j].first.second;
                j++;
            }
            if(v[i].first.first > v[0].first.first  &&  v[i].first.second > y)ans[v[i].second]=z;
        }
        for(i=1;i<=n;i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}