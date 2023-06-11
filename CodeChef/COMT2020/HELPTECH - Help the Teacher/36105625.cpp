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
#define PSS pair<string,string>
int main()
{
    FAST();
    int i,n,t;
    double avg;
    pair<PII,PSS>a[102];
    cin >> t;
    while(t--)
    {
        cin >> n;
        avg=0;
        for(i=1;i<=n;i++)
        {
            cin >> a[i].SE.FI >> a[i].SE.SE >> a[i].FI.FI;
            a[i].FI.SE=i,avg+=a[i].FI.FI;
        }
        avg=avg/(double)n;
        sort(a+1,a+n+1);
        for(i=1;i<=n;i++)
        {
            if(a[i].FI.FI < avg)cout << a[i].SE.FI << ' ' << a[i].SE.SE << ' ' << a[i].FI.FI << '\n';
        }
    }
    return 0;
}