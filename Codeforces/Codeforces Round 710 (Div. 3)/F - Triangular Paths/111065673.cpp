#include<bits/stdc++.h>
using namespace std;
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e5+5;
const int mod=1e9+7;
int r[M],c[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,x,y,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> r[i];
        for(i=1;i<=n;i++)cin >> c[i];
        vector<pair<int,int>>v;
        v.emplace_back(1,1);
        for(i=1;i<=n;i++)v.emplace_back(r[i],c[i]);
        sort(v.begin(),v.end());
        ans=0;
        for(i=1;i<=n;i++)
        {
            x=v[i].first-v[i-1].first;
            y=v[i].second-v[i-1].second;
            if((v[i-1].first+v[i-1].second) & 1)ans+=(x-y+1)/2;
            else
            {
                if(x-y)ans+=(x-y)/2;
                else ans+=x;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
//