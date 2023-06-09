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
     LL m,n,x,y,ans=0LL;
    cin >> m >> n;
    map<LL,bool>mp;
    PQ<PLL,V<PLL>,greater<PLL> >pq;
    while(m--)
    {
        cin >> x;
        pq.PS({0,x});
        mp[x]=true;
    }
    V<int>pos;
    while(n > 0LL)
    {
        x=pq.T.FI;
        y=pq.T.SE;
        pq.PP;
        if(mp.find(y-1LL) == mp.E)
        {
            --n;
            ans+=(x+1LL);
            mp[y-1LL]=true;
            pos.PSB(y-1LL);
            pq.PS({x+1LL,y-1LL});
        }
        if(n > 0LL)
        {
            if(mp.find(y+1LL) == mp.E)
            {
                --n;
                ans+=(x+1LL);
                mp[y+1LL]=true;
                pos.PSB(y+1LL);
                pq.PS({x+1LL,y+1LL});
            }
        }
    }
    cout << ans << '\n';
    for(int p : pos)cout << p << ' ';
    return 0;
}