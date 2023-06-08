#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+1;
const int N=2e5+5;
const int mod=1e9+7;
int u[N];
long long ans[N];
vector<long long>v[N];
int main()
    FAST();
    int i,j,l,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            ans[i]=0;
            v[i].clear();
            cin >> u[i];
        }
        for(i=1;i<=n;i++)
        {
            cin >> x;
            v[u[i]].emplace_back(x);
        }
        for(i=1;i<=n;i++)
        {
            sort(v[i].begin(),v[i].end());
            reverse(v[i].begin(),v[i].end());
        }
        for(i=1;i<=n;i++)
        {
            l=(int)v[i].size();
            if(l)
            {
                for(j=1;j<l;j++)v[i][j]+=v[i][j-1];
                for(j=1;j<=l;j++)
                {
                    x=(l/j)*j;
                    ans[j]+=v[i][x-1];
                }
            }
        }
        for(i=1;i<=n;i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}