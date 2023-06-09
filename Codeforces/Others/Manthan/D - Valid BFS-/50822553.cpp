#include<bits/stdc++.h>
using namespace std;
int pos[200005];
vector<int>adj[200005];
vector<int>mark;
vector<int>ans;
bool visited[200005];
queue<int>q;
bool pos_check(int x,int y)
    return pos[x] < pos[y];
int main()
    int a,b,i,n,x;
    scanf("%d",&n);
    for(i=1; i<n; i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(i=0; i<n; i++)
    {
        scanf("%d",&a);
        mark.push_back(a);
        pos[a]=i;
    }
    for(i=1; i<=n; i++)
    {
        sort(adj[i].begin(),adj[i].end(),pos_check);
    }
    q.push(1);
    while(!q.empty())
    {
        x=q.front();
        visited[x]=1;
        ans.push_back(x);
        q.pop();
        for(i=0; i<adj[x].size(); i++)
        {
            if(visited[adj[x][i]] == 0)
            {
                visited[adj[x][i]]=1;
                q.push(adj[x][i]);
            }
        }
    }
    for(i=0; i<n; i++)
    {
        //cout << mark[i] << ' ' << ans[i] << endl;
        if(mark[i] != ans[i])
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}