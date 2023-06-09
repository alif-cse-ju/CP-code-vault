#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int bit[200005];
LL ans,cost[200005];
vector<int>adj[200005];
int DFS(int node,int par,LL val)
    val=min(val,cost[node]);
    int check;
    int pos=(bit[node] == 1);
    int neg=(bit[node] == -1);
    for(int x : adj[node])
    {
        if(x != par)
        {
            check=DFS(x,node,val);
            if(check >= 0)pos+=check;
            else neg+=(-check);
        }
    }
    ans+=val*min(pos,neg)*2;
    return pos-neg;
int main()
    FAST();
    int i,n,x,y;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> cost[i] >> x >> y;
        bit[i]=x-y;
    }
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    int check=DFS(1,1,(LL)1e18);
    if(check == 0)cout << ans;
    else cout << "-1";
    return 0;
}