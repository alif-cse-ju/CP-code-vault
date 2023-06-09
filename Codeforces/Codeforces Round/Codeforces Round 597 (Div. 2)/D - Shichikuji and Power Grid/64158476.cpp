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
   V<int>build;
V<PII>connect;
int parent[2002];
PII points[2002];
LL city_costs[2002];
PLI power_plant_costs[2002];
PQ<pair<LL,PII>,V<pair<LL,PII> >,greater<pair<LL,PII> > >pq;
 int find_parent(int x)
{
    if(parent[x] == x)return x;
    return parent[x]=find_parent(parent[x]);
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,n,x,y,par_x,par_y;
    LL z,total_cost=0;
    cin >> n;
    for(i=1;i<=n;i++)cin >> points[i].FI >> points[i].SE;
    for(i=1;i<=n;i++)cin >> power_plant_costs[i].FI,power_plant_costs[i].SE=i;
    for(i=1;i<=n;i++)cin >> city_costs[i],parent[i]=i;
    for(i=1;i<=n;i++)
    {
        pq.PS({power_plant_costs[i].FI,{0,i}});
        for(j=i+1;j<=n;j++)pq.PS({(city_costs[i]+city_costs[j])*(abs(points[i].FI-points[j].FI)+abs(points[i].SE-points[j].SE)),{i,j}});
    }
    while(!pq.EM)
    {
        z=pq.T.FI;
        x=pq.T.SE.FI;
        y=pq.T.SE.SE;
        pq.PP;
        par_x=find_parent(x);
        par_y=find_parent(y);
        if(par_x != par_y)
        {
            parent[par_y]=par_x;
            total_cost+=z;
            if(x == 0)build.PSB(y);
            else connect.PSB({x,y});
        }
    }
    cout << total_cost << '\n';
    cout << build.SZ << '\n';
    for(auto node : build)cout << node << ' ';
    cout << '\n';
    cout << connect.SZ << '\n';
    for(auto node : connect)cout << node.FI << ' ' << node.SE << '\n';
    return 0;
}