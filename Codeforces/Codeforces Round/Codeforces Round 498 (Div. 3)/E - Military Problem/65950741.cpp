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
    PII nodes[200002];
V<int>adj[200002];
bool visited[200002];
int time_cnt,ans[200002];
 void run_dfs(int x)
{
    if(visited[x])return;
    visited[x]=true;
    ans[++time_cnt]=x;
    nodes[x].FI=time_cnt;
    for(int y : adj[x])run_dfs(y);
    nodes[x].SE=time_cnt;
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,q,x,y;
    cin >> n >> q;
    for(i=2;i<=n;i++)cin >> x,adj[x].PSB(i);
    run_dfs(1);
    while(q--)
    {
        cin >> x >> y;
        --y;
        if(nodes[x].FI+y <= nodes[x].SE)cout << ans[nodes[x].FI+y] << '\n';
        else cout << "-1\n";
    }
    return 0;
}