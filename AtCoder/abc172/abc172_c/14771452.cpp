#include<bits/stdc++.h>

using namespace std;

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
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};




LL a[200005],b[200005];

int main()
{
    FAST();
    LL i,k,m,n,x,y,ans=0;
    cin >> n >> m >> k;
    for(i=1;i<=n;i++)cin >> a[i],a[i]+=a[i-1];
    for(i=1;i<=m;i++)cin >> b[i],b[i]+=b[i-1];
    for(i=0;i<=n   &&  a[i] <= k;i++)
    {
        y=i;
        x=k-a[i];
        x=upper_bound(b+1,b+m+1,x)-b-1;
        ans=max(ans,x+y);
    }
    cout << ans;
    return 0;
}
