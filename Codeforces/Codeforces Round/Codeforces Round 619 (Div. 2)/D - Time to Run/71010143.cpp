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
     LL i,m,n,k,x,y,ans;
    cin >> n >> m >> k;
    ans=4*m*n-2*m-2*n;
    if(ans < k)
    {
        cout << "NO";
        return 0;
    }
    V<PIS>v;
    cout << "YES\n";
    if(n == 1)
    {
        v.PSB({min(k,m-1),"R"});
        k-=min(k,m-1);
        if(k > 0)v.PSB({min(k,m-1),"L"});
    }
    else if(m == 1)
    {
        v.PSB({min(k,n-1),"D"});
        k-=min(k,n-1);
        if(k > 0)v.PSB({min(k,n-1),"U"});
    }
    else
    {
        x=(m-1)*4+1;
        y=k/x;
        k%=x;
        if(y == n)k+=x,--y;
        for(i=1;i<=y;i++)
        {
            v.PSB({m-1,"R"});
            v.PSB({m-1,"DUL"});
            v.PSB({1,"D"});
        }
        if(k > 0  &&  y == n-1)
        {
            v.PSB({min(m-1,k),"R"}),k-=min(m-1,k);
            if(k > 0)v.PSB({min(m-1,k),"L"}),k-=min(m-1,k);
            if(k > 0)v.PSB({min(n-1,k),"U"}),k=0;
        }
        if(k > 0)
        {
            v.PSB({min(m-1,k),"R"});
            k-=min(m-1,k);
            if(k > 2)
            {
                v.PSB({k/3,"DUL"});
                k%=3;
            }
            if(k == 1)v.PSB({1,"D"});
            else if(k == 2)v.PSB({1,"DU"});
        }
    }
    cout << v.SZ << '\n';
    for(PIS bal : v)cout << bal.FI << ' ' << bal.SE << '\n';
    return 0;
}