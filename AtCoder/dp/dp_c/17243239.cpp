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
LL dp[N][5];

int main()
{
    FAST();
    int i,n,x,y,z;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x >> y >> z;
        if(n == 1)dp[1][1]=x,dp[1][2]=y,dp[1][3]=z;
        else
        {
            dp[i][1]=x+max(dp[i-1][2],dp[i-1][3]);
            dp[i][2]=y+max(dp[i-1][1],dp[i-1][3]);
            dp[i][3]=z+max(dp[i-1][1],dp[i-1][2]);
        }
    }
    cout << max(dp[n][1],max(dp[n][2],dp[n][3]));
    return 0;
}
