#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
bool mark[N];
int R[N],S[N],ans[N];
vector<pair<int,int>>v[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,m,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)
        {
            cin >> R[i];
            mark[i]=0;
        }
        for(i=1;i<=m;i++)
        {
            cin >> x;
            v[i].clear();
            S[x]=i,ans[i]=0;
        }
        for(i=1;i<=m;i++)
        {
            cin >> k;
            while(k--)
            {
                cin >> x;
                v[i].emplace_back(R[x],x);
            }
            sort(v[i].begin(),v[i].end());
        }
        for(i=1;i<=m  &&  n;i++)
        {
            x=S[i];
            for(auto it : v[x])
            {
                if(!mark[it.second])
                {
                    n--;
                    ans[x]=it.second;
                    mark[it.second]=1;
                    break;
                }
            }
        }
        cout << ans[1] << '\n';
    }
    return 0;
}
//