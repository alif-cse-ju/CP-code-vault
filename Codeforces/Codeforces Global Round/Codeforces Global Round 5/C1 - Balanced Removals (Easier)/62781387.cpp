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
    PQ<pair<PII,PII> >pqxy,pqx,pq;
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,x,y,z;
    pair<PII,PII>a;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x >> y >> z;
        pqxy.PS({{x,y},{z,i}});
    }
    while(!pqxy.EM)
    {
        a=pqxy.T;
        pqxy.PP;
        if(pqxy.EM  ||  pqxy.T.FI != a.FI)pqx.PS(a);
        else
        {
            cout << a.SE.SE << ' ' << pqxy.T.SE.SE << '\n';
            pqxy.PP;
        }
    }
    while(!pqx.EM)
    {
        a=pqx.T;
        pqx.PP;
        if(pqx.EM  ||  pqx.T.FI.FI != a.FI.FI)pq.PS(a);
        else
        {
            cout << a.SE.SE << ' ' << pqx.T.SE.SE << '\n';
            pqx.PP;
        }
    }
    while(!pq.EM)
    {
        cout << pq.T.SE.SE << ' ';
        pq.PP;
        cout << pq.T.SE.SE << '\n';
        pq.PP;
    }
    return 0;
}