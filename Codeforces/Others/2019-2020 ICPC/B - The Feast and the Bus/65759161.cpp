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
    int teams[8002];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,k,x,y;
    LL cnt,ans=1e18;
    cin >> n >> k;
    for(i=0;i<n;i++)cin >> x,++teams[x];
    sort(teams+1,teams+k+1);
    int low=teams[k],high=teams[k];
    for(i=1;i<=k/2;i++)high=max(high,teams[i]+teams[k-i+1]);
    for(i=low;i<=high;i++)
    {
        x=1,y=k,cnt=0;
        while(x <= y)
        {
            ++cnt;
            if(teams[x]+teams[y] <= i)++x,--y;
            else --y;
        }
        ans=min(ans,cnt*i);
    }
    cout << ans;
    return 0;
}