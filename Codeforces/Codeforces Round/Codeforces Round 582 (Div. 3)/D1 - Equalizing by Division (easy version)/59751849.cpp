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
    int freq[200005];
V<int>num;
PQ<PII,V<PII>,greater<PII> >pq[200005];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,k,x,y,mx=0;
    cin >> n >> k;
    for(i=0;i<n;i++)
    {
        cin >> x;
        if(!freq[x])
        {
            num.PSB(x);
            mx=max(mx,x);
        }
        freq[x]++;
    }
    int cnt;
    for(i=0;i<num.SZ;i++)
    {
        x=y=num[i];
        cnt=0;
        while(y > 0)
        {
            pq[y].PS(MP(cnt,freq[x]));
            ++cnt;
            y/=2;
        }
    }
    int ans=INT_MAX,rem;
    for(i=1;i<=mx;i++)
    {
        rem=k;
        cnt=0;
        while(rem > 0  &&  !pq[i].EM)
        {
            cnt+=min(rem,pq[i].T.SE)*pq[i].T.FI;
            rem-=pq[i].T.SE;
            pq[i].PP;
        }
        if(rem <= 0)
        {ans=min(ans,cnt);}
    }
    cout << ans;
    return 0;
}