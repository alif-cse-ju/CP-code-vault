#include<bits/stdc++.h>
using namespace std;
const int M=1e3+5;
vector<int>adj[M];
int T,a[M],par[M];
void DFS(int x,int p)
    a[++T]=x, par[x]=p;
    for(int y : adj[x])
    {
        if(p ^ y)DFS(y,x);
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,mx,m,n,r,x,y;
    cin >> n;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    DFS(1,0);
    cout << "? " << n;
    for(i=1;i<=n;i++)cout << ' ' << i;
    cout << endl;
    cin >> mx;
    l=2,r=n;
    while(l < r)
    {
        m=(l+r) >> 1;
        cout << "? " << m;
        for(i=1;i<=m;i++)cout << ' ' << a[i];
        cout << endl;
        cin >> x;
        if(x == mx)r=m;
        else l=m+1;
    }
    y=a[r], x=par[y];
    cout << "! " << x << ' ' << y << endl;
    return 0;
}