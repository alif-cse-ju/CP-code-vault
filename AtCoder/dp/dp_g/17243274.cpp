#include<bits/stdc++.h>

using namespace std;

#define G getline
#define C clear()
#define B begin()
#define F front()
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
#define LL long long
#define ULL unsigned long long
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<LL,int>
#define PLL pair<LL,LL>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<LL,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)





//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};




const int N=1e5+5;
int dp[N];
vector<int>adj[N];

int DFS(int cur)
{
    if(dp[cur] > -1)return dp[cur];
    dp[cur]=0;
    for(int x : adj[cur])dp[cur]=max(dp[cur],1+DFS(x));
    return dp[cur];
}

int main()
{
    FAST();
    int i,m,n,x,y;
    cin >> n >> m;
    while(m--)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
    }
    memset(dp,-1,sizeof(dp));
    for(i=1;i<=n;i++)
    {
        if(dp[i] == -1)DFS(i);
    }
    x=0;
    for(i=1;i<=n;i++)
    {
        if(dp[i] > dp[x])x=i;
    }
    cout << dp[x];
    return 0;
}
