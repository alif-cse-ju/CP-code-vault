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
     int i,n,t,x,y,ans,a[200004];
    bool mark0;
    MII mp1,mp2;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=2*n;i++)cin >> a[i];
        mp1.C,mp2.C;
        x=y=0;
        mark0=false;
        ans=INT_MAX;
        for(i=1;i<=n;i++)
        {
            if(a[i] == 1)++x;
            else ++y;
            mp1[i]=x-y;
            if(x == y)mark0=true;
        }
        x=y=0;
        for(i=2*n;i>n;i--)
        {
            if(a[i] == 1)++x;
            else ++y;
            mp2[x-y]=2*n-i+1;
        }
        for(i=1;i<=n;i++)
        {
            if(mp2.find(-mp1[i]) != mp2.E)ans=min(ans,n-mp2[-mp1[i]]+n-i);
            else if(mp1[i] == 0)ans=min(ans,2*n-i);
        }
        cout << min(ans,2*n-mp2[0]) << '\n';
    }
    return 0;
}