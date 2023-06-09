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
    int cnt[30][2005];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,k,n,t,x,y,ans,a[2005];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<27;i++)
        {
            for(j=1;j<=n;j++)cnt[i][j]=0;
        }
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            for(j=1;j<27;j++)cnt[j][i]=cnt[j][i-1];
            cnt[a[i]][i]++;
        }
        ans=0;
        for(i=1;i<27;i++)ans=max(ans,cnt[i][n]);
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                x=min(cnt[a[i]][i],cnt[a[i]][n]-cnt[a[i]][j-1]);
                y=0;
                for(k=1;k<27;k++)
                {
                    if(k != a[i])y=max(y,cnt[k][j-1]-cnt[k][i]);
                }
                ans=max(ans,2*x+y);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}