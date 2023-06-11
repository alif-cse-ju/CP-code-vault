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
bool rev[155];
char s[155][155];
int a[155],dp[22505];
int main()
{
    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,j,n,t,cnt,sum,preSum;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=0;i<n;i++)
        {
            rev[i]=false;
            cin >> s[i];
            cnt=0;
            for(j=0;j<n/2;j++)cnt+=(s[i][j] == '1');
            for(j=n/2;j<n;j++)cnt-=(s[i][j] == '1');
            a[i]=cnt;
        }
        sum=0;
        for(i=0;i<n;i++)
        {
            if(a[i] < 0)
            {
                a[i]=-a[i];
                rev[i]=true;
            }
            sum+=a[i];
        }
        dp[0]=-1;
        for(i=1;i<=sum;i++)dp[i]=-2;
        for(i=0;i<n;i++)
        {
            for(j=sum;j>=a[i];j--)
            {
                if(dp[j] == -2  &&  dp[j-a[i]] != -2)dp[j]=i;
            }
        }
        preSum=0;
        for(i=sum/2;i>=0;i--)
        {
            if(dp[i] != -2)
            {
                preSum=i;
                break;
            }
        }
        while(preSum > 0)
        {
            rev[dp[preSum]]^=true;
            preSum-=a[dp[preSum]];
        }
        for(i=0;i<n;i++)
        {
            if(rev[i])
            {
                for(j=n-1;j>=0;j--)cout << s[i][j];
            }
            else
            {
                for(j=0;j<n;j++)cout << s[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}