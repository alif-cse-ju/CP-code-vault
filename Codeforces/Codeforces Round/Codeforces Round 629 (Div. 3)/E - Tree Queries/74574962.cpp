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
    V<int>adj[200005];
int visitedTime,depth[200005],parent[200005],tin[200005],tout[200005],nodes[200005];
 void runDFS(int x,int par,int dep)
{
    parent[x]=par;
    depth[x]=dep;
    tin[x]=++visitedTime;
    for(int y: adj[x])
    {
        if(y != par)runDFS(y,x,dep+1);
    }
    tout[x]=++visitedTime;
}
 bool isAnc(int x,int y)
{
    return tin[x] <= tin[y]  &&  tout[y] <= tout[x];
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     bool valid;
    int i,k,m,n,x,y;
    cin >> n >> m;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    runDFS(1,-1,0);
    while(m--)
    {
        cin >> k;
        for(i=0;i<k;i++)cin >> nodes[i];
        x=nodes[0];
        for(i=0;i<k;i++)
        {
            if(depth[nodes[i]] > depth[x])x=nodes[i];
        }
        for(i=0;i<k;i++)
        {
            if(nodes[i] != x)
            {
                if(parent[nodes[i]] != -1)nodes[i]=parent[nodes[i]];
            }
        }
        valid=true;
        for(i=0;i<k  &&  valid;i++)valid &= isAnc(nodes[i],x);
        if(valid)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}