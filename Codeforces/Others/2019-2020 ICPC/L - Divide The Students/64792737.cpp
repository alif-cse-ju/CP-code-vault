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
     int a,b,c,t,x;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
        if(a == c)
        {
            if(b > a)
            {
                b-=a;
                cout << a+b/3+(b%3 > 0) << '\n';
            }
            else cout << a << '\n';
        }
        else
        {
            if(a > c)swap(a,c);
            if(b >= c)cout << (a+b+c)/3+((a+b+c)%3 > 0) << '\n';
            else
            {
                x=b;
                if(a > b)
                {
                    while(b < c  &&  b < a)++b,--c;
                    while(a < c  &&  x)++a,++b,c-=2,--x;
                }
                else
                {
                    while(a < b  &&  a < c  &&  x)++a,--c,--x;
                    if(x > 0)
                    {
                        while(a < c  &&  x)++a,++b,c-=2,--x;
                        while(b > c+2  &&  x)++a,++c,b-=2,--x;
                    }
                }
                cout << max(a,(b+c)/2+((b+c) & 1)) << '\n';
            }
        }
    }
    return 0;
}