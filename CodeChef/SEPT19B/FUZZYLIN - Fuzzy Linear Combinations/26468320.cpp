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
int a[100002];
map<int,LL>ans;
map<int,LL>gcd_cnt[100002];
map<int,set<int> >distinct_gcd;
LL find_ans(int x)
{
    LL cnt=0;
    for(int i=1; i*i<=x; i++)
    {
        if(x%i == 0)
        {
            if(ans.count(i))
            {
                cnt+=ans[i];
            }
            if(i*i != x)
            {
                if(ans.count(x/i))
                {
                    cnt+=ans[x/i];
                }
            }
        }
    }
    return cnt;
}
int main()
{
//    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("input.txt","w",stdout);
    int i,n,q,cur;
    S("%d",&n);
    for(i=0; i<n; i++)
    {
        S("%d",&a[i]);
    }
    distinct_gcd[0].insert(a[0]);
    gcd_cnt[0][a[0]]++;
    for(i=1; i<n; i++)
    {
        distinct_gcd[i].insert(a[i]);
        gcd_cnt[i][a[i]]++;
        for(auto x: distinct_gcd[i-1])
        {
            cur=__gcd(a[i],x);
            distinct_gcd[i].insert(cur);
            gcd_cnt[i][cur]+=gcd_cnt[i-1][x];
        }
    }
    for(auto x : distinct_gcd)
    {
        for(auto y: x.SE)
        {
            ans[y]+=gcd_cnt[x.FI][y];
        }
    }
    int x;
    S("%d",&q);
    while(q--)
    {
        S("%d",&x);
        P("%lld\n",find_ans(x));
    }
    return 0;
}