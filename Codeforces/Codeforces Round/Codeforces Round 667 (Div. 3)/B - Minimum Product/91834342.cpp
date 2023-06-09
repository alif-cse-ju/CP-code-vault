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
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
      int main()
{
    FAST();
    int t;
    LL a,_a,b,_b,x,y,n,_n,check;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> x >> y >> n;
        _a=a,_b=b,_n=n;
        check=min(n,a-x);
        n-=check,a-=check;
        check=min(n,b-y);
        n-=check,b-=check;
        check=min(_n,_b-y);
        _n-=check,_b-=check;
        check=min(_n,_a-x);
        _n-=check,_a-=check;
        cout << min(a*b,_a*_b) << '\n';
    }
    return 0;
}