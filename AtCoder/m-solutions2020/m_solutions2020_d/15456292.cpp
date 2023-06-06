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






int main()
{
    FAST();
    LL i,n,a[85],ans=1000,cnt=0,cur=1000;
    bool buy[85],sell[85];
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i],buy[i]=sell[i]=true;
    for(i=1;i<n;i++)
    {
        if(a[i] >= a[i+1])buy[i]=sell[i+1]=false;
        else buy[i+1]=sell[i]=false;
    }
    for(i=1;i<=n;i++)
    {
        if(buy[i])cnt=cur/a[i],cur%=a[i];
        else if(sell[i])cur+=cnt*a[i],cnt=0,ans=max(ans,cur);
    }
    cout << ans;
    return 0;
}
