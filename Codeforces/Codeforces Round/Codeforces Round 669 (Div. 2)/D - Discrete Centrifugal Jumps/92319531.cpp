#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int a[N],dist[N];
vector<int>adj[N];
void BuildGraph(int const& n)
    int i;
    stack<int>stk;
    for(i=1;i<=n;i++)
    {
        while(!stk.empty()  &&  a[stk.top()] > a[i])stk.pop();
        if(!stk.empty())adj[stk.top()].emplace_back(i);
        stk.emplace(i);
    }
    while(!stk.empty())stk.pop();
    for(i=n;i>0;i--)
    {
        while(!stk.empty()  &&  a[stk.top()] > a[i])stk.pop();
        if(!stk.empty())adj[i].emplace_back(stk.top());
        stk.emplace(i);
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    BuildGraph(n);
    for(i=1;i<=n;i++)a[i]*=-1;
    BuildGraph(n);
    for(i=1;i<=n;i++)dist[i]=i-1;
    for(i=1;i<n;i++)
    {
        for(int x: adj[i])dist[x]=min(dist[x],dist[i]+1);
    }
    cout << dist[n];
    return 0;
}