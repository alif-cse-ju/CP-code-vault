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
V<int>adj[100005];
int odd,cnt,color[100005];
int main()
{
    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("input.txt","w",stdout);
    int i,m,n,t,x,y,mx;
    bool flag;
    cin >> t;
    while(t--)
    {
        mx=1;
        cin >> n >> m;
        for(i=1; i<=n; i++)color[i]=1,adj[i].C;
        if(!(m & 1))
        {
            while(m--)cin >> x >> y;
        }
        else
        {
            while(m--)
            {
                cin >> x >> y;
                adj[x].PSB(y);
                adj[y].PSB(x);
            }
            flag=false;
            for(i=1; i<=n; i++)
            {
                if(adj[i].SZ & 1)
                {
                    mx=2;
                    color[i]=2;
                    flag=true;
                    break;
                }
            }
            if(!flag)
            {
                m=0,mx=3;
                while(m < n)
                {
                    ++m;
                    if(adj[m].SZ > 0)break;
                }
                color[m]=2;
                color[adj[m][0]]=3;
            }
        }
        cout << mx << '\n' << color[1];
        for(i=2; i<=n; i++)cout << ' ' << color[i];
        cout << '\n';
    }
    return 0;
}