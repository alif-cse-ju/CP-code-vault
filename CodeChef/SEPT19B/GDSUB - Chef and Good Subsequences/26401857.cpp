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
const LL mod=1000000007;
V<int>v;
int k,n,cnt[8002];
LL dp[1010][1010];
LL run_dp(int cur,int taken)
{
    if(cur == n)
    {
        return (taken <= min(k,n));
    }
    if(dp[cur][taken] != -1)
    {
        return dp[cur][taken];
    }
    LL ways=0;
    ways=(ways+run_dp(cur+1,taken))%mod;
    ways=(ways+cnt[v[cur]]*run_dp(cur+1,taken+1))%mod;
    return dp[cur][taken]=ways;
}
int main()
{
//    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("input.txt","w",stdout);
    int i,x;
    S("%d %d",&n,&k);
    for(i=0; i<n; i++)
    {
        S("%d",&x);
        if(!cnt[x])
        {
            v.PSB(x);
        }
        cnt[x]++;
    }
    n=v.SZ;
    memset(dp,-1,sizeof(dp));
    run_dp(0,0);
    cout << dp[0][0];
    return 0;
}