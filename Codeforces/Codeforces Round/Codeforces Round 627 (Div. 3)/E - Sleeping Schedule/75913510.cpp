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
    int h,n,l,r,a[2005],dp[2005][2005];
 int runDP(int cur,int cnt)
{
    if(cur > n)return 0;
    if(dp[cur][cnt] != -1)return dp[cur][cnt];
    int x=(cur-1)*h+a[cur]-cnt;
    x%=h;
    if(x < 0)x+=h;
    int ans=(x >= l  &&  x <= r)+runDP(cur+1,cnt);
    --x;
    if(x < 0)x+=h;
    ans=max(ans,(x >= l  &&  x <= r)+runDP(cur+1,cnt+1));
    return dp[cur][cnt]=ans;
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     //CF 1324E
    int i;
    cin >> n >> h >> l >> r;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        a[i]+=a[i-1];
    }
    memset(dp,-1,sizeof(dp));
    cout << runDP(1,0);
    return 0;
}