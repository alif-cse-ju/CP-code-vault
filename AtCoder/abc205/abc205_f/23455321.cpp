#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=5e2+5;
const int N=2e5+5;
const int mod=1e9+7;

struct edge
{
    int to,cap,flow;
};

vector<edge>Graph[N];
int iter[N],level[N];

void AddEdge(int from,int to,int cap)
{
    Graph[from].emplace_back((edge){to,cap,(int)Graph[to].size()});
    Graph[to].emplace_back((edge){from,0,(int)Graph[from].size()-1});
}

void BFS(int node)
{
    memset(level,-1,sizeof(level));
    queue<int>q;
    level[node]=0;
    q.emplace(node);
    int i,l;
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        l=(int)Graph[node].size();
        for(i=0;i<l;i++)
        {
            edge &e=Graph[node][i];
            if(e.cap > 0  &&  level[e.to] < 0)
            {
                q.emplace(e.to);
                level[e.to]=level[node]+1;
            }
        }
    }
}

int DFS(int v,int t,int f)
{
    if(v == t)return f;
    int l=(int)Graph[v].size(),check;
    for(int &i=iter[v];i<l;i++)
    {
        edge &e=Graph[v][i];
        if(e.cap > 0  &&  level[v] < level[e.to])
        {
            check=DFS(e.to,t,min(f,e.cap));
            if(check > 0)
            {
                e.cap-=check;
                Graph[e.to][e.flow].cap+=check;
                return check;
            }
        }
    }
    return 0;
}

int FindDinicMaxFlow(int s,int t)
{
    int flow=0,check;
    while(true)
    {
        BFS(s);
        if(level[t] < 0)return flow;
        memset(iter,0,sizeof(iter));
        while((check=DFS(s,t,INT_MAX)) > 0)flow+=check;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c,d,i,j,m,n,q;
    cin >> n >> m >> q;
    for(i=1;i<=n;i++)AddEdge(0,i,1);
    for(i=1;i<=m;i++)AddEdge(300+i,401,1);
    for(i=1;i<=q;i++)
    {
        AddEdge(100+i,200+i,1);
        cin >> a >> b >> c >> d;
        for(j=a;j<=c;j++)AddEdge(j,100+i,1);
        for(j=b;j<=d;j++)AddEdge(200+i,300+j,1);
    }
    cout << FindDinicMaxFlow(0,401);
    return 0;
}