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
#define LL long long
#define ULL unsigned long long
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<LL,int>
#define PLL pair<LL,LL>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<LL,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
bool visited[2005];
vector<int>adj[2005];
void DFS(int x)
{
    if(visited[x])return;
    visited[x]=1;
    for(int y : adj[x])DFS(y);
}
int main()
{
    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    string a,b,s,d;
    int i,n,t,x,y,cnt=0;
    cin >> t;
    while(t--)
    {
        for(i=1;i<=cnt;i++)visited[i]=0,adj[i].clear();
        cin >> n >> s >> d;
        map<string,int>mp;
        mp[s]=1,mp[d]=cnt=2;
        while(n--)
        {
            cin >> a >> b;
            if(mp.find(a) == mp.end())mp[a]=x=++cnt;
            else x=mp[a];
            if(mp.find(b) == mp.end())mp[b]=y=++cnt;
            else y=mp[b];
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        DFS(1);
        if(visited[2]   ||  s == d)cout << "Quarantine\n";
        else cout << "Stay Home, Stay Safe\n";
    }
    return 0;
}