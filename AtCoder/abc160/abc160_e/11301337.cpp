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






int main()
{
    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int a,b,c,i,x,y,z;
    cin >> x >> y >> a >> b >> c;
    PQ<int>pqr,pqg,pqc;
    for(i=0;i<a;i++)cin >> z,pqr.PS(z);
    for(i=0;i<b;i++)cin >> z,pqg.PS(z);
    for(i=0;i<c;i++)cin >> z,pqc.PS(z);
    PQ<int,V<int>,greater<int> >pqr1,pqg1;
    LL ans=0;
    while(x--)
    {
        pqr1.emplace(pqr.T);
        ans+=pqr.T;
        pqr.PP;
    }
    while(y--)
    {
        pqg1.emplace(pqg.T);
        ans+=pqg.T;
        pqg.PP;
    }
    while(!pqc.EM)
    {
        x=pqc.T;
        pqc.PP;
        y=min(pqr1.T,pqg1.T);
        if(y >= x)break;
        ans+=x-y;
        if(y == pqr1.T)
        {
            pqr1.PP;
            pqr1.emplace(x);
        }
        else
        {
            pqg1.PP;
            pqg1.emplace(x);
        }
    }
    cout << ans;
    return 0;
}
