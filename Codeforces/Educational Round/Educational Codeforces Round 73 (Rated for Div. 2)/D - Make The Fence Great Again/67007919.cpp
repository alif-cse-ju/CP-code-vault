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
    LL dp[300002][3];
int cost[300002];
int height[300002];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,k,n,q;
    cin >> q;
    while(q--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            cin >> height[i] >> cost[i];
            dp[i][0]=dp[i][1]=dp[i][2]=1e18;
        }
        dp[1][0]=0LL;
        dp[1][1]=cost[1];
        dp[1][2]=2LL*cost[1];
        for(i=2;i<=n;i++)
        {
            for(j=0;j<3;j++)
            {
                for(k=0;k<3;k++)
                {
                    if(height[i-1]+j != height[i]+k)dp[i][k]=min(dp[i][k],dp[i-1][j]+k*cost[i]);
                }
            }
        }
        cout << min(dp[n][0],min(dp[n][1],dp[n][2])) << '\n';
    }
    return 0;
}