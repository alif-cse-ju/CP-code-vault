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
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int N=1e6;
int n;
LL s,a[N+2],sum[N+2];
bool Check(int k)
{
    int i;
    for(i=k;i<=n;i++)
    {
        if(sum[i]-sum[i-k] > s)return 1;
    }
    return 0;
}
int main()
{
    FAST();
    int i,k,ans,low,mid,high;
    cin >> n >> k >> s;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        sum[i]=sum[i-1]+a[i];
    }
    if(sum[n] <= s  ||  k == n)
    {
        cout << "-1";
        return 0;
    }
    low=1,high=n;
    while(low <= high)
    {
        mid=(low+high) >> 1;
        if(Check(mid))
        {
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    cout << max(ans,k+1);
    return 0;
}