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
PII days[1001][1001];
int main()
{
    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,j,m,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)cin >> days[i][j].FI,days[i][j].SE=days[i][j].FI;
        }
        for(i=2;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                x=days[i-1][j].SE;
                if(j > 1)x=max(x,days[i-1][j-1].SE);
                if(j < m)x=max(x,days[i-1][j+1].SE);
                days[i][j].SE=max(x,days[i][j].SE);
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)cout << (days[i][j].SE <= days[i][j].FI);
            cout << '\n';
        }
    }
    return 0;
}