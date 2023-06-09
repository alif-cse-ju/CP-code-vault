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
     int i,j,n,t,a[205],b[105],c[105];
    bool mark[205];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=2*n;i++)mark[i]=false;
        for(i=1;i<=n;i++)cin >> b[i],mark[b[i]]=true;
        n*=2,j=0;
        for(i=1;i<=n;i++)
        {
            if(!mark[i])c[++j]=i;
        }
        for(i=2;i<=n;i+=2)
        {
            a[i-1]=b[i/2];
            for(j=1;j<=n/2;j++)
            {
                if(!mark[c[j]]  &&  c[j] > b[i/2])
                {
                    a[i]=c[j];
                    mark[c[j]]=true;
                    break;
                }
            }
            if(j > n/2)break;
        }
        if(i <= n)cout << "-1";
        else
        {
            for(i=1;i<=n;i++)cout << a[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}