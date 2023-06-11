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
pair<double,double>a[5002];
pair<double,double>b[5002];
pair<double,double>c[5002];
double x_to_a[5002],x_to_b[5002];
double find_distance(double a,double b,double x,double y)
{
    return sqrt((a-x)*(a-x)+(b-y)*(b-y));
}
int main()
{
    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("input.txt","w",stdout);
    int i,j,l,n,m,k,t;
    double x,y,mn,dis;
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        cin >> n >> m >> k;
        for(i=1;i<=n;i++)cin >> a[i].FI >> a[i].SE;
        for(i=1;i<=m;i++)cin >> b[i].FI >> b[i].SE;
        for(i=1;i<=k;i++)cin >> c[i].FI >> c[i].SE;
        mn=DBL_MAX;
        V<double>a_to_c[n+2],b_to_c[m+2];
        l=max(m,n);
        for(i=1;i<=k;i++)
        {
            for(j=1;j<=l;j++)
            {
                if(j <= n)
                {
                    dis=find_distance(c[i].FI,c[i].SE,a[j].FI,a[j].SE);
                    if(a_to_c[j].EM)a_to_c[j].PSB(dis);
                    else if(dis < a_to_c[j][0])a_to_c[j][0]=dis;
                }
                if(j <= m)
                {
                    dis=find_distance(c[i].FI,c[i].SE,b[j].FI,b[j].SE);
                    if(b_to_c[j].EM)b_to_c[j].PSB(dis);
                    else if(dis < b_to_c[j][0])b_to_c[j][0]=dis;
                }
            }
        }
        for(i=1;i<=n;i++)x_to_a[i]=find_distance(x,y,a[i].FI,a[i].SE);
        for(i=1;i<=m;i++)x_to_b[i]=find_distance(x,y,b[i].FI,b[i].SE);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                dis=find_distance(a[i].FI,a[i].SE,b[j].FI,b[j].SE);
                mn=min(mn,min(x_to_a[i]+dis+b_to_c[j][0],x_to_b[j]+dis+a_to_c[i][0]));
            }
        }
        cout << fixed << setprecision(10) << mn << '\n';
    }
    return 0;
}