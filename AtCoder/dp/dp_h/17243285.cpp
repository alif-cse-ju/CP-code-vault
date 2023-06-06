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




const int N=1002;
const LL mod=1e9+7;
int m,n;
char s[N][N];
LL dp[N][N];

LL DP(int i,int j)
{
    if(i > n  ||  j > m  ||  s[i][j] == '#')return 0;
    if(i == n  &&  j == m)return 1;
    LL &ans=dp[i][j];
    if(ans > -1)return ans;
    ans=DP(i+1,j)+DP(i,j+1);
    ans%=mod;
    return ans;
}

int main()
{
    FAST();
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> s[i]+1;
    memset(dp,-1,sizeof(dp));
    cout << DP(1,1);
    return 0;
}
