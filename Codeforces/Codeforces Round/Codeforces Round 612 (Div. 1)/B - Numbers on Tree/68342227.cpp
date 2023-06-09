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
    bool ache;
V<PII>v[2002];
V<int>adj[2002];
PII dfs_time[2002];
int rt,ans[2002],cnt[2002],visited_time;
 void run_dfs1(int node)
{
    dfs_time[node].FI=++visited_time;
    for(int x : adj[node])run_dfs1(x);
    dfs_time[node].SE=visited_time;
    if(cnt[node] > dfs_time[node].SE-dfs_time[node].FI)ache=false;
}
 void find_ans(int node)
{
    for(int x : adj[node])
    {
        find_ans(x);
        for(PII y : v[x])v[node].PSB(y);
    }
    if(v[node].EM)
    {
        v[node].PSB({1,node});
        return;
    }
    sort(v[node].B,v[node].E);
    for(int i=0;i<v[node].SZ;i++)
    {
        v[node][i].FI=i+1;
        if(i >= cnt[node])++v[node][i].FI;
    }
    v[node].PSB({cnt[node]+1,node});
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,x;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x >> cnt[i];
        if(x != 0)adj[x].PSB(i);
        else rt=i;
    }
    ache=true;
    run_dfs1(rt);
    if(!ache)
    {
        cout << "NO";
        return 0;
    }
    find_ans(rt);
    for(PII nodes : v[rt])ans[nodes.SE]=nodes.FI;
    cout << "YES\n";
    for(i=1;i<=n;i++)cout << ans[i] << ' ';
    return 0;
}