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
     int ans[5003];
bool visited[5003];
bool visited_mark[5003];
V<PII>adj[5003];
bool flag=true;
 void run_dfs(int node)
{
    visited[node]=true;
    visited_mark[node]=true;
    int i,x,y;
    for(i=0; i<adj[node].SZ; i++)
    {
        x=adj[node][i].FI;
        y=adj[node][i].SE;
        if(!visited_mark[x])
        {
            ans[y]=1;
            run_dfs(x);
        }
        else if(visited[x])
        {
            ans[y]=2;
            flag=false;
        }
        else
        {
            ans[y]=1;
        }
    }
    visited[node]=false;
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("input.txt","w",stdout);
     int i,n,m,x,y;
    cin >> n >> m;
    for(i=0; i<m; i++)
    {
        cin >> x >> y;
        adj[x].PSB(MP(y,i));
    }
    for(i=1; i<=n; i++)
    {
        if(!visited_mark[i])
            run_dfs(i);
    }
    if(flag)
    {
        cout << "1\n";
        for(i=0; i<m; i++)
        {
            cout << "1 ";
        }
    }
    else
    {
        cout << "2\n";
        for(i=0; i<m; i++)
        {
            cout << ans[i] << ' ';
        }
    }
    return 0;
}
//KUET IUPC G