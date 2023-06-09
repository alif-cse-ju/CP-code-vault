#include<bits/stdc++.h>
using namespace std;
#define FI first
#define SE second
#define LL long long
#define PLL pair<LL,LL>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
bool flag;
vector<int>adj[100002];
LL m,ppl[100002],hpy[100002];
PLL DFS(int node,int par)
    PLL temp;
    LL ans=ppl[node];
    LL khrp=0,check;
    for(int x : adj[node])
    {
        if(x ^ par)
        {
            temp=DFS(x,node);
            ans+=temp.FI;
            khrp+=temp.SE;
        }
    }
    if(abs(hpy[node]) > ans  ||  (ans-abs(hpy[node]))%2)
    {
        flag=false;
        return {0,0};
    }
    check=(ans-abs(hpy[node]))/2;
    if(hpy[node] < 0)check+=abs(hpy[node]);
    if(max(0LL,check-ppl[node]) > khrp)
    {
        flag=false;
        return {0,0};
    }
    return {ans,check};
}
 int main()
{
    FAST();
    PLL check;
    int i,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)
        {
            cin >> ppl[i];
            adj[i].clear();
        }
        for(i=1;i<=n;i++)cin >> hpy[i];
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        flag=true;
        check=DFS(1,0);
        if(flag)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}