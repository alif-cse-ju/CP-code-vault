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
    V<int>adj[200005];
int ans[200005],dp[200005],mark[200005];
 void runDFS(int cur,int par)
{
    dp[cur]=mark[cur];
    for(int x : adj[cur])
    {
        if(x != par)
        {
            runDFS(x,cur);
            dp[cur]+=max(0,dp[x]);
        }
    }
}
 void findAns(int cur,int par)
{
    ans[cur]=dp[cur];
    for(int x : adj[cur])
    {
        if(x != par)
        {
            dp[cur]-=max(0,dp[x]);
            dp[x]+=max(0,dp[cur]);
            findAns(x,cur);
            dp[x]-=max(0,dp[cur]);
            dp[cur]+=max(0,dp[x]);
        }
    }
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     //CF 1324F
    int i,n,x,y;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> mark[i];
        if(!mark[i])--mark[i];
    }
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    runDFS(1,-1);
    findAns(1,-1);
    for(i=1;i<=n;i++)cout << ans[i] << ' ';
    return 0;
}