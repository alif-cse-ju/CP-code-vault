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
    V<PII>ans;
V<int>adj[200002];
bool visited[200002];
 void run_dfs(int x,int y)
{
    if(visited[y])return;
    visited[y]=true;
    ans.PSB(x,y);
    for(int z : adj[y])run_dfs(y,z);
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,m,n,x,y;
    cin >> n >> m;
    while(m--)
    {
        cin >> x >> y;
        adj[x].PSB(y);
        adj[y].PSB(x);
    }
    y=0;
    for(i=1;i<=n;i++)
    {
        if(adj[i].SZ > y)x=i,y=adj[i].SZ;
    }
    visited[x]=true;
    for(int z : adj[x])ans.PSB(x,z),visited[z]=true;
    for(int z : adj[x])
    {
        for(int bal : adj[z])
        {
            if(!visited[bal])run_dfs(z,bal);
        }
    }
    for(PII bal : ans)cout << bal.FI << ' ' << bal.SE << '\n';
    return 0;
}