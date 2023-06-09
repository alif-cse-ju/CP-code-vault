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
    int mn[102],mx[102];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,s,x;
    cin >> n >> s;
    if(s == 0  ||  n*9 < s)
    {
        if(n == 1  &&  s == 0)
        {
            cout << "0 0";
        }
        else
        cout << -1 << ' ' << -1;
        return 0;
    }
    x=s-1;
    for(i=n;i>1 && x > 0; i--)
    {
        mn[i]=min(9,x);
        x-=9;
    }
    mn[1]=1+max(x,0);
    for(i=1; i<=n  &&  s > 0; i++)
    {
        mx[i]=min(9,s);
        s-=9;
    }
    for(i=1; i<=n; i++)
    {
        cout << mn[i];
    }
    cout << ' ';
    for(i=1; i<=n; i++)
    {
        cout << mx[i];
    }
    return 0;
}