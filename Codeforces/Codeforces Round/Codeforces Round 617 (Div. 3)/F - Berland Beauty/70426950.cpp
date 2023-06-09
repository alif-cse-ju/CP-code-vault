#include<bits/stdc++.h>
using namespace std;
#define S scanf
#define P printf
#define G getline
#define SZ size()
#define C clear()
#define B begin()
#define F front()
#define T top()
#define E end()
#define EM empty()
#define V vector
#define Q queue
#define DQ deque
#define PQ priority_queue
#define ST stack
#define FI first
#define SE second
#define PI acos(-1)
#define PS push
#define PP pop()
#define PSF push_front
#define PSB emplace_back
#define PPF pop_front()
#define PPB pop_back()
#define MP make_pair
#define LL long long int
#define ULL unsigned long long int
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<long long int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<long long int,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
     //int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
    V<int>adj[5002];
PII edges[5002];
int parent[5002];
bool visited[5002];
int cost[5002][5002];
PQ<pair<int,PII> >queries;
 void run_dfs(int cur,int par)
{
    if(visited[cur])return;
    parent[cur]=par;
    visited[cur]=true;
    for(int x : adj[cur])run_dfs(x,cur);
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     bool flag;
    int i,j,m,n,x,y,z;
    cin >> n;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].PSB(y);
        adj[y].PSB(x);
        edges[i]={x,y};
    }
    cin >> m;
    while(m--)
    {
        cin >> x >> y >> z;
        queries.PS({z,{x,y}});
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)cost[i][j]=cost[j][i]=INT_MAX;
    }
    while(!queries.EM)
    {
        z=queries.T.FI;
        x=queries.T.SE.FI;
        y=queries.T.SE.SE;
        queries.PP;
        for(i=1;i<=n;i++)parent[i]=visited[i]=0;
        run_dfs(x,x);
        x=parent[y];
        flag=false;
        while(x != y)
        {
            if(cost[x][y] == z  ||  cost[x][y] == INT_MAX)cost[x][y]=cost[y][x]=z,flag=true;
            y=x,x=parent[y];
        }
        if(!flag)
        {
            cout << "-1";
            return 0;
        }
    }
    for(i=1;i<n;i++)
    {
        x=edges[i].FI;
        y=edges[i].SE;
        cout << min(cost[x][y],1000000) << ' ';
    }
    return 0;
}