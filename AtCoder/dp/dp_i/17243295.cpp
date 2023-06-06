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




const int N=3005;
int n;
double dp[N][N],prob[N];

double DP(int cur,int nichi)
{
    if(cur > n)return nichi > n-nichi;
    double &ans=dp[cur][nichi];
    if(ans > -1.00)return ans;
    return ans=prob[cur]*DP(cur+1,nichi+1)+(1.00-prob[cur])*DP(cur+1,nichi);
}

int main()
{
    FAST();
    int i,j;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> prob[i];
        for(j=0;j<=n;j++)dp[i][j]=-1.00;
    }
    cout << fixed << setprecision(10) << DP(1,0);
    return 0;
}
