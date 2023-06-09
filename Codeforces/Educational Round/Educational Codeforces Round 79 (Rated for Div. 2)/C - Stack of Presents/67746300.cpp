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
     int i,m,n,t,x,y;
    LL ans,cnt;
    cin >> t;
    while(t--)
    {
        ans=cnt=0LL;
        Q<int>q1,q2;
        map<int,bool>visited;
        cin >> n >> m;
        for(i=0;i<n;i++)cin >> x,q1.PS(x);
        for(i=0;i<m;i++)cin >> x,q2.PS(x);
        while(!q2.EM)
        {
            x=q2.F,q2.PP;
            if(visited[x])--cnt;
            else
            {
                while(q1.F != x)
                {
                    y=q1.F,q1.PP;
                    ++cnt;
                    visited[y]=true;
                }
                q1.PP;
                ans+=cnt*2LL;
            }
            ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}