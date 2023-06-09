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
int evenOdd[2],leafCnt[100005];
 void runDFS(int cur,int par,int bit)
{
    if(adj[cur].SZ == 1)evenOdd[bit]=1;
    for(int x : adj[cur])
    {
        if(x != par)runDFS(x,cur,bit ^ 1);
    }
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,x,y,maxVal;
    cin >> n;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    for(i=1;i<=n;i++)
    {
        if(adj[i].SZ == 1)++leafCnt[adj[i][0]];
    }
    maxVal=n-1;
    for(i=1;i<=n;i++)maxVal-=max(0,leafCnt[i]-1);
    runDFS(1,0,0);
    cout << 2*(evenOdd[0]+evenOdd[1])-1 << ' ' << maxVal;
    return 0;
}