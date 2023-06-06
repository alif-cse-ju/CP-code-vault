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




LL a[100002],mul[100002];

PLL solve(LL n,LL min_sum)
{
    LL cnt=0,sum=0,x=1;
    for(int i=n;i>0;i--)
    {
        while(x <= n  &&  a[i]+a[x] < min_sum)++x;
        cnt+=(n-x+1LL);
        sum+=(n-x+1LL)*a[i]+mul[x];
    }
    return {cnt,sum};
}

int main()
{
    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    PLL check;
    LL i,m,n,low,mid,high,ans=0LL;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    for(i=n;i>0;i--)mul[i]=mul[i+1]+a[i];
    low=1,high=2*a[n];
    while(low <= high)
    {
        mid=(low+high) >> 1LL;
        check=solve(n,mid);
        if(check.FI >= m)
        {
            ans=check.SE-mid*(check.FI-m);
            low=mid+1LL;
        }
        else high=mid-1LL;
    }
    cout << ans;
    return 0;
}
