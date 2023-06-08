#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int parent[N];
pair<int,pair<int,int>>edges[N];
int FindParent(int x)
    if(parent[x] == x)return x;
    return parent[x]=FindParent(parent[x]);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long ans;
    int i,k,m,n,t,x,y,z,mn,mx,px,py;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        for(i=1;i<=n;i++)parent[i]=i;
        for(i=1;i<=m;i++)
        {
            cin >> x >> y >> z;
            edges[i].first=z;
            edges[i].second.first=x;
            edges[i].second.second=y;
        }
        mx=0,mn=INT_MAX;
        ans=0;
        sort(edges+1,edges+m+1);
        for(i=1;i<=m;i++)
        {
            z=edges[i].first;
            x=edges[i].second.first;
            y=edges[i].second.second;
            px=FindParent(x);
            py=FindParent(y);
            if(px != py)
            {
                parent[py]=px;
                mx=max(mx,z);
                if(z > k)ans+=z-k;
            }
        }
        if(mx < k)
        {
            for(i=1;i<=m;i++)
            {
                z=edges[i].first;
                if(z < k)mx=z;
                else
                {
                    mn=z;
                    break;
                }
            }
            ans=k-mx;
            if(mn < INT_MAX)ans=min(ans,(long long)mn-k);
        }
        cout << ans << '\n';
    }
    return 0;
}