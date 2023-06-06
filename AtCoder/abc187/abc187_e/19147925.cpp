#include<bits/stdc++.h>

using namespace std;

#define G getline
#define C clear()
#define B begin()
#define F front()
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
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};




const int N=2e5+5;
const int mod=1e9+7;

pair<int,int>edge[N];
vector<int>adj[N];
long long ans[N];
int n,cnt,parent[N],_StArT[N],_eNd[N];

void DFS(int x,int par)
{
    parent[x]=par;
    _StArT[x]=++cnt;
    for(int y : adj[x])
    {
        if(y ^ par)DFS(y,x);
    }
    _eNd[x]=cnt;
}

void Update(int i,int val)
{
    ans[i]+=val;
}

long long Query(int i)
{
    return ans[i];
}

int main()
{
    FAST();
    int i,x,y,z,q,op;
    cin >> n;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
        edge[i].first=x,edge[i].second=y;
    }
    DFS(1,0);
    cin >> q;
    while(q--)
    {
        cin >> op >> i >> z;
        x=edge[i].first;
        y=edge[i].second;
        if(op == 1)
        {
            if(parent[x] == y)
            {
                Update(_StArT[x],z);
                Update(_eNd[x]+1,-z);
            }
            else
            {
                Update(1,z);
                Update(_StArT[y],-z);
                Update(_eNd[y]+1,z);
            }
        }
        else
        {
            if(parent[y] == x)
            {
                Update(_StArT[y],z);
                Update(_eNd[y]+1,-z);
            }
            else
            {
                Update(1,z);
                Update(_StArT[x],-z);
                Update(_eNd[x]+1,z);
            }
        }
    }
    for(i=2;i<=n;i++)ans[i]+=ans[i-1];
    for(i=1;i<=n;i++)cout << Query(_StArT[i]) << '\n';
    return 0;
}
