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
     int i,j,k,ans=0;
    LL ax,ay,bx,by,xs,ys,t,x[105],y[105];
    cin >> x[0] >> y[0] >> ax >> ay >> bx >> by >> xs >> ys >> t;
    for(k=1;x[k-1] < 3e16  &&  y[k-1] < 3e16;k++)
    {
        x[k]=ax*x[k-1]+bx;
        y[k]=ay*y[k-1]+by;
    }
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
        {
            if(abs(x[i]-xs)+abs(y[i]-ys)+abs(x[i]-x[j])+abs(y[i]-y[j]) <= t)ans=max(ans,abs(i-j)+1);
        }
    }
    cout << ans;
    return 0;
}