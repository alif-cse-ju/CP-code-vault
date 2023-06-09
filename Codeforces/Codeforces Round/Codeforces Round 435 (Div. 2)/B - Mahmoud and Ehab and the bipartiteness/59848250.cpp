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
   int color[100003];
V<int>adj[100003];
V<int>colored_nodes[3];
 void run_dfs(int node,int clr)
{
    if(color[node])
    {
        return ;
    }
    color[node]=clr;
    colored_nodes[clr].PSB(node);
    int i,l=adj[node].SZ;
    clr=(clr%2)+1;
    for(i=0; i<l; i++)
    {
        run_dfs(adj[node][i],clr);
    }
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("input.txt","w",stdout);
     int i,n,x,y;
    cin >> n;
    for(i=1; i<n; i++)
    {
        cin >> x >> y;
        adj[x].PSB(y);
        adj[y].PSB(x);
    }
    run_dfs(1,1);
    LL ans=0;
    int l1=colored_nodes[1].SZ;
    int l2=colored_nodes[2].SZ;
    if(l1 <= l2)
    {
        for(i=0; i<l1; i++)
        {
            x=colored_nodes[1][i];
            ans+=(l2-adj[x].SZ);
        }
    }
    else
    {
        for(i=0; i<l2; i++)
        {
            x=colored_nodes[2][i];
            ans+=(l1-adj[x].SZ);
        }
    }
    cout << ans;
    return 0;
}