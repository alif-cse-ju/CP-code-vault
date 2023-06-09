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
     int x1,x2,y1,y2;    cin >> x1 >> y1 >> x2 >> y2;
    int x3,x4,y3,y4;    cin >> x3 >> y3 >> x4 >> y4;
    int x5,x6,y5,y6;    cin >> x5 >> y5 >> x6 >> y6;
    if(x1 >= x3  &&  x2 <= x4  &&  y1 >= y3  &&  y2 <= y4)                                                cout << "NO";
    else if(x1 >= x5  &&  x2 <= x6  &&  y1 >= y5  &&  y2 <= y6)                                           cout << "NO";
    else if(x1 >= x3  &&  x2 <= x6  &&  x5-x4 < 1  &&  y1 >= y3  &&  y2 <= y4  &&  y1 >= y5  &&  y2 <= y6)cout << "NO";
    else if(x1 >= x5  &&  x2 <= x4  &&  x3-x6 < 1  &&  y1 >= y3  &&  y2 <= y4  &&  y1 >= y5  &&  y2 <= y6)cout << "NO";
    else if(y1 >= y3  &&  y2 <= y6  &&  y5-y4 < 1  &&  x1 >= x3  &&  x2 <= x4  &&  x1 >= x5  &&  x2 <= x6)cout << "NO";
    else if(y1 >= y5  &&  y2 <= y4  &&  y3-y6 < 1  &&  x1 >= x3  &&  x2 <= x4  &&  x1 >= x5  &&  x2 <= x6)cout << "NO";
    else                                                                                                  cout << "YES";
    return 0;
}