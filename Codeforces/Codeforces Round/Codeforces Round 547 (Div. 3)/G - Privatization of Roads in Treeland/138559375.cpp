#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
int ans[M];
vector<pair<int,int>>adj[M];
int DFS(int x,int p,const int& v)
    int cnt=((int)adj[x].size() > v);
    for(auto [y,i] : adj[x])
    {
        if(p ^ y)cnt += DFS(y,x,v);
    }
    return cnt;
void DFS2(int x,int p,const int& v)
    int c=0;
    if(p)
    {
        for(auto [y,i] : adj[x])
        {
            if(y == p)
            {
                c=ans[i];
                break;
            }
        }
    }
    if((int)adj[x].size() > v)
    {
        for(auto [y,i] : adj[x])ans[i]=max(1,c);
    }
    else
    {
        int ii=1;
        for(auto [y,i] : adj[x])
        {
            if(p ^ y)
            {
                if(ii == c)++ii;
                ans[i]=ii++;
            }
        }
    }
    for(auto [y,i] : adj[x])
    {
        if(p ^ y)DFS2(y,x,v);
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,k,m,n,r,x,y;
    cin >> n >> k;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y,i);
        adj[y].emplace_back(x,i);
    }
    l=1,r=n-1;
    while(l <= r)
    {
        m=(l+r) >> 1;
        if(DFS(1,0,m) <= k)r=m-1;
        else l=m+1;
    }
    cout << r+1 << '\n';
    DFS2(1,0,r+1);
    for(i=1;i<n;i++)cout << ans[i] << ' ';
    return 0;
}