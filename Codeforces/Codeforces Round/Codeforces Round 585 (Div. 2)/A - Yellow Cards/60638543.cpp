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
//    freopen("input.txt","w",stdout);
     int a1,a2,k1,k2,n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    int ans1=0,ans2=0;
    int n1=n,n2=n;
    n1-=(a1*(k1-1)+a2*(k2-1));
    if(n1 > 0)
    {
        ans1=min(n1,a1+a2);
    }
    if(k1 <= k2)
    {
        ans2=min(a1,n2/k1);
        n2-=(ans2*k1);
        if(n2 > 0)
        {
            ans2+=min(a2,n2/k2);
        }
    }
    else
    {
        ans2=min(a2,n2/k2);
        n2-=(ans2*k2);
        if(n2 > 0)
        {
            ans2+=min(a1,n2/k1);
        }
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}