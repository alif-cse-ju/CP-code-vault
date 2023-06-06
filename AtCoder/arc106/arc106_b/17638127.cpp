#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int a[N],b[N];
bool visited[N];
vector<int>adj[N];
long long add,sub;

void DFS(int cur)
{
    if(visited[cur])return;
    visited[cur]=1;
    if(a[cur] > b[cur])sub+=a[cur]-b[cur];
    else add+=b[cur]-a[cur];
    for(int it : adj[cur])DFS(it);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,m,n,x,y;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)cin >> b[i];
    while(m--)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    for(i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            add=sub=0;
            DFS(i);
            if(add != sub)
            {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}
