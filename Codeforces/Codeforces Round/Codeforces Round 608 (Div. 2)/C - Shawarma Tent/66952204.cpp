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
     int n,sx,sy,x,y,cntx1=0,cntx2=0,cnty1=0,cnty2=0;
    cin >> n >> sx >> sy;
    while(n--)
    {
        cin >> x >> y;
        if(x > sx  &&  y > sy)++cntx1,++cnty1;
        else if(x == sx  &&  y > sy)++cnty1;
        else if(x < sx  &&  y > sy)++cntx2,++cnty1;
        else if(x < sx  &&  y == sy)++cntx2;
        else if(x < sx  &&  y < sy)++cntx2,++cnty2;
        else if(x == sx  &&  y < sy)++cnty2;
        else if(x > sx  &&  y < sy)++cnty2,++cntx1;
        else ++cntx1;
    }
    if(cntx1 >= cntx2  &&  cntx1 >= cnty1  &&  cntx1 >= cnty2)
    {
        cout << cntx1 << '\n';
        cout << sx+1 << ' ' << sy;
    }
    else if(cntx2 >= cntx1  &&  cntx2 >= cnty1  &&  cntx2 >= cnty2)
    {
        cout << cntx2 << '\n';
        cout << sx-1 << ' ' << sy;
    }
    else if(cnty1 >= cntx1  &&  cnty1 >= cntx2  &&  cnty1 >= cnty2)
    {
        cout << cnty1 << '\n';
        cout << sx << ' ' << sy+1;
    }
    else
    {
        cout << cnty2 << '\n';
        cout << sx << ' ' << sy-1;
    }
    return 0;
}