#include<bits/stdc++.h>

using namespace std;

const int N=4e5+5;
const int mod=1e9+7;

bool visited[N];
vector<int>adj[N];
int edgeCnt,nodeCnt;

void DFS(int x)
{
    if(visited[x])return;
    ++nodeCnt;
    visited[x]=1;
    for(int y : adj[x])
    {
        ++edgeCnt;
        DFS(y);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    set<int>st;
    int i,n,x,y,ans=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> x >> y;
        st.insert(x);
        st.insert(y);
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    for(int it : st)
    {
        if(visited[it])continue;
        edgeCnt=nodeCnt=0;
        DFS(it);
        edgeCnt/=2;
        if(edgeCnt < nodeCnt)ans+=edgeCnt;
        else ans+=nodeCnt;
    }
    cout << ans;
    return 0;
}