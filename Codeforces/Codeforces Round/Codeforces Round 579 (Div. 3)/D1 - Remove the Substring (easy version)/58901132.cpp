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
#define FAST() ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
       int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,l=0,la,lb;
    string a,b;
    cin >> a >> b;
    la=a.SZ,lb=b.SZ;
    int first[lb+5],last[lb+5];
    for(i=0; i<la; i++)
    {
        if(a[i] == b[l])
        {
            first[++l]=i+1;
            if(l == lb)
            {
                break;
            }
        }
    }
    l=lb-1;
    for(i=la-1; i>-1; i--)
    {
        if(a[i] == b[l])
        {
            last[l+1]=i+1;
            if(l == 0)
            {
                break;
            }
            else
            {
                l--;
            }
        }
    }
    int ans=max(la-first[lb],last[1]-1);
    for(i=1; i<lb; i++)
    {
        ans=max(ans,last[i+1]-first[i]-1);
    }
    cout << ans;
    return 0;
}