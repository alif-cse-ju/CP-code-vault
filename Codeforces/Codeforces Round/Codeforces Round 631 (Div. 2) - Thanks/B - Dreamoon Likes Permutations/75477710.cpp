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
     int i,l,n,t,mx1,mx2,a[200005];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        set<int>st1,st2;
        mx1=mx2=0;
        for(i=1;i<=n;i++)
        {
            if(st1.find(a[i]) == st1.E)mx1=max(mx1,a[i]),st1.insert(a[i]);
            else break;
        }
        for( ;i<=n;i++)st2.insert(a[i]),mx2=max(mx2,a[i]);
        if(mx1+mx2 == n  &&  mx1  &&  mx2  &&  mx1 == st1.SZ  &&  mx2 == st2.SZ)
        {
            l=min(mx1,mx2);
            mx1=mx2=0;
            for(i=1;i<=l;i++)mx1=max(mx1,a[i]);
            for(i=n;i>n-l;i--)mx2=max(mx2,a[i]);
            if(mx1 == mx2  &&  l < n-l)cout << "2\n" << l  << ' ' << n-l << '\n' << n-l << ' ' << l << '\n';
            else cout << "1\n" << (int)st1.SZ << ' ' << (int)st2.SZ << '\n';
            continue;
        }
        st1.C,st2.C;
        mx1=mx2=0;
        for(i=n;i>0;i--)
        {
            if(st1.find(a[i]) == st1.E)mx1=max(mx1,a[i]),st1.insert(a[i]);
            else break;
        }
        for( ;i>0;i--)st2.insert(a[i]),mx2=max(mx2,a[i]);
        if(mx1+mx2 == n  &&  mx1  &&  mx2  &&  mx1 == st1.SZ  &&  mx2 == st2.SZ)
        {
            l=min(mx1,mx2);
            mx1=mx2=0;
            for(i=1;i<=l;i++)mx1=max(mx1,a[i]);
            for(i=n;i>n-l;i--)mx2=max(mx2,a[i]);
            if(mx1 == mx2  &&  l < n-l)cout << "2\n" << l  << ' ' << n-l << '\n' << n-l << ' ' << l << '\n';
            else cout << "1\n" << (int)st2.SZ << ' ' << (int)st1.SZ << '\n';
        }
        else cout << "0\n";
    }
    return 0;
}