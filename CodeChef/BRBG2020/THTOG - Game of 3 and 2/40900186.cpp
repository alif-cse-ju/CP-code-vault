#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int indegree[102];
long long a[102];
vector<int>adj[N];
void DFS(int x,int par)
{
    cout << a[x] << ' ';
    for(int y : adj[x])
    {
        if(y ^ par)DFS(y,x);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(a[i]*2LL == a[j])adj[i].emplace_back(j),++indegree[j];
            else if(a[j]%3LL == 0  &&  a[j]/3LL == a[i])adj[j].emplace_back(i),++indegree[i];
        }
    }
    for(i=1;i<=n;i++)
    {
        if(!indegree[i])
        {
            DFS(i,i);
            return 0;
        }
    }
    return 0;
}