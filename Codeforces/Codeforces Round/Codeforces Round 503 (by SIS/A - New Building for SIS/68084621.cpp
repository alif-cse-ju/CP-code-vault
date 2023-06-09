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
     int a,b,h,n,q,x1,y1,x2,y2,ans;
    cin >> n >> h >> a >> b >> q;
    while(q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2)cout << abs(y1-y2) << '\n';
        else
        {
            ans=abs(x1-x2);
            if(y1 < a)ans+=a-y1,y1=a;
            else if(y1 > b)ans+=y1-b,y1=b;
            if(y2 < a)ans+=a-y2,y2=a;
            else if(y2 > b)ans+=y2-b,y2=b;
            ans+=abs(y1-y2);
            cout << ans << '\n';
        }
    }
    return 0;
}