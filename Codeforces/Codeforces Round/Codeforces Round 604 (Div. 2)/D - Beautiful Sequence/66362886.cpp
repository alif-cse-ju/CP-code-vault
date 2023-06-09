#include<bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
 //template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
 //int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
      int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int a,b,c,d,i;
    cin >> a >> b >> c >> d;
    DQ<int>dq;
    if(abs(a-b) <= 1  &&  c == d  &&  c == 0)
    {
        cout << "YES\n";
        if(b > a)cout << "1 ";
        for(i=0;i<min(a,b);i++)cout << "0 1 ";
        if(a > b)cout << "0";
        return 0;
    }
    if(abs(c-d) <= 1  &&  a == b  &&  a == 0)
    {
        cout << "YES\n";
        if(d > c)cout << "3 ";
        for(i=0;i<min(c,d);i++)cout << "2 3 ";
        if(c > d)cout << "2";
        return 0;
    }
    if(a <= b  &&  d <= c)
    {
        for(i=0;i<a;i++)dq.PSB(0),dq.PSB(1);
        for(i=0;i<d;i++)dq.PSB(2),dq.PSB(3);
        b-=a,c-=d,a=d=0;
        while(c > 0  &&  b > 0)
        {
            dq.PSB(2);
            dq.PSB(1);
            --b,--c;
        }
        if(b == 1)dq.PSF(1),b=0;
        if(c == 1)dq.PSB(2),c=0;
        if(a == b  &&  c == d)
        {
            cout << "YES\n";
            while(!dq.EM)
            {
                cout << dq.F << ' ';
                dq.PPF;
            }
            return 0;
        }
    }
    cout << "NO";
    return 0;
}