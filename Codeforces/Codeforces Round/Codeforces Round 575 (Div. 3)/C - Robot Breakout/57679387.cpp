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
        int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,q,a,b,c,d,x,y,bam,dan,upor,nich;
    cin >> q;
    while(q--)
    {
        cin >> n;
        bam=nich=-100000;
        dan=upor=100000;
        for(i=0; i<n; i++)
        {
            cin >> x >> y >> a >> b >> c >> d;
            if(a == 0)
            {
                bam=max(bam,x);
            }
            if(b == 0)
            {
                upor=min(upor,y);
            }
            if(c == 0)
            {
                dan=min(dan,x);
            }
            if(d == 0)
            {
                nich=max(nich,y);
            }
        }
        if(nich > upor  ||  bam > dan)
        {
            cout << "0\n";
        }
        else
        {
            cout << '1' << ' ' << bam << ' ' << nich << '\n';
        }
    }
    return 0;
}