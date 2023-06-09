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
    PQ<PII>pq;
int cnt[202];
PII segments[202];
V<int>ans,segments_mark[202];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,n,k,x,sum=0;
    cin >> n >> k;
    for(i=1;i<=n;i++)
    {
        cin >> segments[i].FI >> segments[i].SE;
        segments_mark[segments[i].FI].PSB(i);
        ++cnt[segments[i].FI];
        --cnt[segments[i].SE+1];
    }
    for(i=1;i<=200;i++)
    {
        sum+=cnt[i];
        for(j=0;j<segments_mark[i].SZ;j++)
        {
            x=segments_mark[i][j];
            pq.PS({segments[x].SE,x});
        }
        while(sum > k)
        {
            x=pq.T.SE;
            pq.PP;
            ans.PSB(x);
            --sum;
            ++cnt[segments[x].SE+1];
        }
    }
    cout << ans.SZ << '\n';
    for(i=0;i<ans.SZ;i++)cout << ans[i] << ' ';
    return 0;
}