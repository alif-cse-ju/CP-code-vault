#include<bits/stdc++.h>
using namespace std;
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e2+5;
const int N=2e5+5;
const int mod=1e9+7;
int lvl[M];
vector<int>adj[M],path;
void DFS(int x)
    lvl[x]=0;
    for(int y : adj[x])
    {
        DFS(y);
        lvl[x]=max(lvl[x],lvl[y]+1);
    }
int Go(int cur,int k)
    --k;
    path.emplace_back(cur);
    if(!k)return 0;
    for(int it : adj[cur])
    {
        k=Go(it,k);
        path.emplace_back(cur);
        if(!k)return 0;
    }
    return k;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,n,p,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1; i<=n; i++)adj[i].clear();
        for(i=2; i<=n; i++)
        {
            cin >> p;
            adj[p].emplace_back(i);
        }
        DFS(1);
        for(i=1; i<=n; i++)sort(adj[i].begin(),adj[i].end(),[&] (int x,int y)
        {
            return lvl[x] > lvl[y];
        });
        path.clear();
        Go(1,k);
        reverse(path.begin(),path.end());
        set<int>st;
        for(p=0; ;p++)
        {
            st.insert(path[p]);
            if((int)st.size() == k)break;
        }
        cout << p << '\n';
        for(i=0;i<=p;i++)cout << path[i] << ' ';
        cout << '\n';
    }
    return 0;
}
//