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
    int n,a[102],dp[102][52][52][2];
 int run_DP(int idx,int odd,int even,bool mark)
{
    if(idx > n)return 0;
    if(dp[idx][odd][even][mark] > -1)return dp[idx][odd][even][mark];
    int ans=INT_MAX;
    if(a[idx] > 0)ans=(a[idx]+mark)%2+run_DP(idx+1,odd,even,a[idx]%2);
    else
    {
        if(odd > 0)ans=min(ans,!mark+run_DP(idx+1,odd-1,even,true));
        if(even > 0)ans=min(ans,mark+run_DP(idx+1,odd,even-1,false));
    }
    return dp[idx][odd][even][mark]=ans;
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,odd,even,ans=INT_MAX;
    cin >> n;
    even=n/2;
    odd=(n+1)/2;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i] > 0)
        {
            if(a[i] & 1)--odd;
            else --even;
        }
    }
    memset(dp,-1,sizeof(dp));
    if(a[1] == 0)
    {
        if(odd > 0)ans=min(ans,run_DP(2,odd-1,even,1));
        if(even > 0)ans=min(ans,run_DP(2,odd,even-1,0));
    }
    else ans=run_DP(2,odd,even,a[1]%2);
    cout << ans;
    return 0;
}