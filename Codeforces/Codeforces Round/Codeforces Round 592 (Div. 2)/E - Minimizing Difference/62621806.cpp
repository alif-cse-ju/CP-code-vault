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
    MII cnt;
V<int>v;
DQ<int>dq;
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     LL a,b,i,k,n,x,y;
    cin >> n >> k;
    for(i=0;i<n;i++)
    {
        cin >> x;
        if(cnt.find(x) == cnt.E)v.PSB(x);
        ++cnt[x];
    }
    sort(v.B,v.E);
    for(auto z : v)dq.PSB(z);
    while(k > 0  &&  dq.SZ > 1)
    {
        x=dq.F;
        y=dq.back();
        a=cnt[x],b=cnt[y];
        dq.PPF,dq.PPB;
        //cout << x << "--" << a << ' ' << y << "--" << b << "   " << k << endl;
        if(a <= b)
        {
            dq.PSB(y);
            if(k >= (dq.F-x)*a)
            {
                k-=(dq.F-x)*a;
                cnt[dq.F]+=a;
            }
            else if(k >= a)
            {
                x+=(k/a);
                k%=a;
                cnt[x]=a;
                dq.PSF(x);
            }
            else {dq.PSF(x);break;}
        }
        else
        {
            dq.PSF(x);
            if(k >= (y-dq.back())*b)
            {
                k-=(y-dq.back())*b;
                cnt[dq.back()]+=b;
            }
            else if(k >= b)
            {
                y-=(k/b);
                k%=b;
                cnt[y]=b;
                dq.PSB(y);
            }
            else {dq.PSB(y);break;}
        }
    }
    if(dq.SZ == 1)cout << 0;
    else cout << dq.back()-dq.F;
    return 0;
}