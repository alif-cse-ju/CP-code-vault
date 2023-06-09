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
#define PSB emplace_back
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
    int cnt[35];
LL a[100005];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,t;
    bool flag;
    LL x,ans,sum,val;
    cin >> t;
    while(t--)
    {
        cin >> val >> n;
        sum=0;
        for(i=1;i<=n;i++)cin >> a[i],sum+=a[i];
        if(sum < val)
        {
            cout << "-1\n";
            continue;
        }
        sort(a+1,a+n+1);
        memset(cnt,0,sizeof(cnt));
        for(i=1;i<=n;i++)
        {
            x=0;
            while((1 << x) != a[i])++x;
            ++cnt[x];
        }
        ans=sum=flag=0;
        for(i=0;i<33;i++)
        {
            x=(val >> i) & 1;
            sum=sum/2+cnt[i];
            if(x  &&  sum)x=0,--sum;
            if(x)flag=1;
            if(sum  &&  flag)--sum,flag=0;
            if(flag)++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}