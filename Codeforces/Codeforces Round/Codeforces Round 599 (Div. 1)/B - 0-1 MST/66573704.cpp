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
    map<PII,bool>mp;
set<int>unvisited;
 void run_dfs(int x)
{
    V<int>adj;
    for(auto y : unvisited)
    {
        if(mp.find({x,y}) == mp.E)adj.PSB(y);
    }
    for(auto y : adj)unvisited.erase(unvisited.find(y));
    for(auto y : adj)run_dfs(y);
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,m,n,x,y,ans=0;
    cin >> n >> m;
    while(m--)
    {
        cin >> x >> y;
        mp[{x,y}]=mp[{y,x}]=1;
    }
    for(i=1;i<=n;i++)unvisited.insert(i);
    for(i=1;i<=n;i++)
    {
        if(unvisited.SZ == 0)break;
        auto temp=unvisited.B;
        ++ans;
        unvisited.erase(temp);
        x=*temp;
        run_dfs(x);
    }
    cout << ans-1;
    return 0;
}