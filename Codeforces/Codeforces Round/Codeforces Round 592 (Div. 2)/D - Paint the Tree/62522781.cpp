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
#define PSB push_back
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
    V<int>adj[100002];
int cost[5][100002];
int n,nodes[100002];
bool visited[100002];
 void run_dfs(int x)
{
    if(visited[x])return;
    visited[x]=1;
    nodes[++n]=x;
    for(auto y : adj[x])run_dfs(y);
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,x,y,temp[5];
    cin >> n;
    int ans[n+5];
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=n;j++)cin >> cost[i][j];
    }
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].PSB(y);
        adj[y].PSB(x);
    }
    int root;
    for(i=1;i<=n;i++)
    {
        if(adj[i].SZ == 1)root=i;
        else if(adj[i].SZ > 2)
        {
            cout << -1;
            return 0;
        }
    }
    n=0;
    run_dfs(root);
    LL mn=1e18,cnt;
    int colors[]={1,2,3};
    do
    {
        cnt=j=0;
        for(i=1;i<=n;i++,j++)
        {
            cnt+=cost[colors[j%3]][nodes[i]];
        }
        if(cnt < mn)
        {
            mn=cnt;
            temp[0]=colors[0];
            temp[1]=colors[1];
            temp[2]=colors[2];
        }
    }
    while(next_permutation(colors,colors+3));
    cout << mn << '\n';
    for(i=0;i<n;i++)ans[nodes[i+1]]=temp[i%3];
    for(i=1;i<=n;i++)cout << ans[i] << ' ';
    return 0;
}