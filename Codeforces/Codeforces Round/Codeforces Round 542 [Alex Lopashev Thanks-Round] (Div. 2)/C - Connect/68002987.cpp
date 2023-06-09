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
#define PSB emplace_back
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
     int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
    int n;
set<PII>adj1,adj2;
char grid[52][52];
bool visited1[52][52];
bool visited2[52][52];
 void run_dfs1(int x,int y)
{
    if(x < 1  ||  y < 1  ||  x > n  ||  y > n  ||  grid[x][y] == '1'  ||  visited1[x][y])return;
    visited1[x][y]=true;
    adj1.insert({x,y});
    for(int i=0;i<4;i++)run_dfs1(x+dx[i],y+dy[i]);
}
 void run_dfs2(int x,int y)
{
    if(x < 1  ||  y < 1  ||  x > n  ||  y > n  ||  grid[x][y] == '1'  ||  visited2[x][y])return;
    visited2[x][y]=true;
    adj2.insert({x,y});
    for(int i=0;i<4;i++)run_dfs2(x+dx[i],y+dy[i]);
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,x1,x2,y1,y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    for(i=1;i<=n;i++)cin >> grid[i]+1;
    run_dfs1(x1,y1);
    run_dfs2(x2,y2);
     if(adj1 == adj2)
    {
        cout << "0";
        return 0;
    }
    int ans=INT_MAX;
    for(PII u : adj1)
    {
        for(PII v : adj2)ans=min(ans,(u.FI-v.FI)*(u.FI-v.FI)+(u.SE-v.SE)*(u.SE-v.SE));
    }
    cout << ans;
    return 0;
}