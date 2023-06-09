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
    LL n,presum[100005];
 int findAns(LL x)
{
    if(x > presum[n-1])return 1;
    auto pos=lower_bound(presum+1,presum+n,x)-presum;
    int y=x-presum[pos-1];
    if(y & 1)return pos;
    return y/2+pos;
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int t;
    LL i,l,r;
    cin >> t;
    while(t--)
    {
        cin >> n >> l >> r;
        for(i=1;i<=n;i++)presum[i]=presum[i-1]+2*(n-i);
        for(i=l;i<=r;i++)cout << findAns(i) << ' ';
        cout << '\n';
    }
    return 0;
}