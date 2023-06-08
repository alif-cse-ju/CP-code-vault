#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int w[N],degree[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n,t,x,y;
    long long ans;
    cin >> t;
    while(t--)
    {
        ans=0;
        cin >> n;
        for(i=1;i<=n;i++)
        {
            cin >> w[i];
            ans+=w[i];
            degree[i]=0;
        }
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            ++degree[x],++degree[y];
        }
        vector<int>v;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<degree[i];j++)v.emplace_back(w[i]);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(int it : v)
        {
            cout << ans << ' ';
            ans+=it;
        }
        cout << ans << '\n';
    }
    return 0;
}