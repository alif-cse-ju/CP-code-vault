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
     int i,n,x,cnt=0,mn=0,mx;
    cin >> n;
    int a[n+2];
    for(i=1;i<=n;i++)cin >> a[i];
    V<PII>pos;
    sort(a+1,a+n+1);
    x=a[1];
    for(i=1;i<=n;i++)
    {
        if(a[i] == x)++cnt;
        else
        {
            pos.PSB(x,cnt);
            x=a[i],cnt=1;
        }
    }
    pos.PSB(x,cnt);
    if(pos.SZ == 1)
    {
        if(pos[0].SE == 1)cout << "1 1";
        else if(pos[0].SE == 2)cout << "1 2";
        else cout << "1 3";
        return 0;
    }
    for(i=0;i<pos.SZ;i++)
    {
        if(i+2 < pos.SZ  &&  pos[i+2].FI-pos[i].FI == 2)i+=2;
        else if(i+1 < pos.SZ  &&  pos[i+1].FI-pos[i].FI < 3)i++;
        ++mn;
    }
    if(pos[0].SE > 2)mx=3,++pos[0].FI;
    else if(pos[0].SE > 1)mx=2;
    else mx=1,--pos[0].FI;
    for(i=1;i<pos.SZ;i++)
    {
        if(pos[i].FI == pos[i-1].FI)++mx,++pos[i].FI;
        else if(pos[i].FI-1 == pos[i-1].FI)
        {
            if(pos[i].SE > 1)mx+=2,++pos[i].FI;
            else ++mx;
        }
        else if(pos[i].SE > 2)mx+=3,++pos[i].FI;
        else if(pos[i].SE > 1)mx+=2;
        else ++mx,--pos[i].FI;
    }
    cout << mn << ' ' << mx;
    return 0;
}