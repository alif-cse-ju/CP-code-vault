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
int main()
{
    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    PII a[100002];
    int i,m,n,t,l,r,ans,cnt0,cnt[100002];
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=0;i<n;i++)cin >> a[i].FI,a[i].SE=i%m;
        sort(a,a+n);
        cnt0=m,r=0,ans=INT_MAX;
        for(i=0;i<m;i++)cnt[i]=0;
        for(l=0;l<n;l++)
        {
            while(r < n  &&  cnt0 > 0)
            {
                if(cnt[a[r].SE] == 0)--cnt0;
                cnt[a[r++].SE]++;
            }
            if(cnt0 == 0)ans=min(ans,a[r-1].FI-a[l].FI);
            cnt[a[l].SE]--;
            if(cnt[a[l].SE] == 0)++cnt0;
        }
        cout << ans << '\n';
    }
    return 0;
}