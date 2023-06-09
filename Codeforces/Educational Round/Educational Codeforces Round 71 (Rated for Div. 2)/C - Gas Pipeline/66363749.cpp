#include<bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
 //template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
 //int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
      int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int a,b,i,n,t;
    char s[200002];
    LL dp[200002][2];
    cin >> t;
    while(t--)
    {
        cin >> n >> a >> b >> s+1;
        dp[0][0]=b,dp[0][1]=1e18;
        for(i=1;i<=n;i++)
        {
            if(s[i] == '0')dp[i][0]=min(dp[i-1][0]+a+b,dp[i-1][1]+2*(a+b));
            else dp[i][0]=1e18;
            dp[i][1]=min(dp[i-1][1]+a+2*b,dp[i-1][0]+2*(a+b));
        }
        cout << dp[n][0] << '\n';
    }
    return 0;
}