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
     PII temp;
    V<int>ans;
    int i,n,v,x,y,cnt=0,sum=0;
    cin >> n >> v;
    PQ<PII>pq2;
    PQ<PII,V<PII>,greater<PII> >pq1;
    for(i=1;i<=n;i++)
    {
        cin >> x >> y;
        if(x == 1)
        {
            if(cnt < v)
            {
                ++cnt;
                pq1.PS({y,i});
            }
            else
            {
                if(pq1.T.FI < y)
                {
                    pq1.PP;
                    pq1.PS({y,i});
                }
            }
        }
        else pq2.PS({y,i});
    }
    while(cnt+2 <= v  &&  !pq2.EM)
    {
        sum+=pq2.T.FI;
        ans.PSB(pq2.T.SE);
        pq2.PP;
        cnt+=2;
    }
    if(pq2.EM  &&  cnt <= v)
    {
        while(!pq1.EM)sum+=pq1.T.FI,pq1.PP;
        cout << sum << '\n';
        for(i=1;i<=n;i++)cout << i << ' ';
        return 0;
    }
    if(cnt < v)pq1.PS({0,n+1});
    while(!pq1.EM  &&  !pq2.EM)
    {
        temp=pq1.T,pq1.PP;
        if(!pq1.EM   &&  temp.FI+pq1.T.FI < pq2.T.FI)
        {
            if(pq1.T.FI == 0)
            {
                pq1.PS(temp);
                while(!pq2.EM)pq2.PP;
                break;
            }
            sum+=pq2.T.FI;
            ans.PSB(pq2.T.SE);
            pq2.PP;
            pq1.PP;
        }
        else
        {
            pq1.PS(temp);
            while(!pq2.EM)pq2.PP;
        }
    }
    while(!pq1.EM)
    {
        sum+=pq1.T.FI;
        if(pq1.T.SE <= n)ans.PSB(pq1.T.SE);
        pq1.PP;
    }
    cout << sum << '\n';
    for(int idx : ans)cout << idx << ' ';
    return 0;
}