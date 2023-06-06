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




LL dp[2005][2005];

bool check(PLL x,PLL y)
{
    if(x.SE == y.SE)return x.FI < y.FI;
    return x.SE > y.SE;
}

int main()
{
    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    LL i,j,n,x,ans=0;
    V<PLL>v;
    v.emplace_back(0,0);
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        v.emplace_back(i,x);
    }
    sort(v.B+1,v.E,check);
    for(i=1;i<=n;i++)
    {
        dp[i][0]=dp[i-1][0]+v[i].SE*abs(v[i].FI-(n-i+1));
        for(j=1;j<i;j++)dp[i][j]=max(dp[i-1][j-1]+v[i].SE*abs(v[i].FI-j),dp[i-1][j]+v[i].SE*abs(v[i].FI-(n-i+j+1)));
        dp[i][i]=dp[i-1][i-1]+v[i].SE*abs(v[i].FI-i);
    }
    for(i=1;i<=n;i++)ans=max(ans,dp[n][i]);
    cout << ans;
    return 0;
}
