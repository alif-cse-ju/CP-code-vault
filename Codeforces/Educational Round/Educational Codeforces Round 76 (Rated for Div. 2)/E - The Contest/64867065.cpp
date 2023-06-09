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
    int n,idx[200002];
int dp[200002][4];
 int run_DP(int cur,int last)
{
    if(cur > n)return 0;
    if(dp[cur][last] != -1)return dp[cur][last];
    dp[cur][last]=INT_MAX;
    for(int i=max(1,last);i<4;i++)dp[cur][last]=min(dp[cur][last],(idx[cur] != i)+run_DP(cur+1,i));
    return dp[cur][last];
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int a,b,c,x;
    cin >> a >> b >> c;
    n=a+b+c;
    while(a--)cin >> x,idx[x]=1;
    while(b--)cin >> x,idx[x]=2;
    while(c--)cin >> x,idx[x]=3;
    memset(dp,-1,sizeof(dp));
    cout << run_DP(1,0);
    return 0;
}