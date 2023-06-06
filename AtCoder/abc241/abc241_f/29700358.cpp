#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)
#define ll long long

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;

int m,n;
pair<int,int>obstacles[M];
map<pair<int,int>,ll>dist;
map<int,int>rowMap,colMap;
ordered_set<int>row[M],col[M];
priority_queue<tuple<ll,int,int>>pq;

void Dijkstra()
{
    int l,xx,yy,xxx,yyy;
    while(!pq.empty())
    {
        auto [z,x,y]=pq.top();
        pq.pop(), z = z*(-1);
        if(dist.find({x,y}) != dist.end()  &&  dist[{x,y}] != z)continue;
        xx=rowMap[x], yy=colMap[y], ++z;

        ///same row er col gula
        l=row[xx].order_of_key(y);
        if(l)
        {
            yyy=*(row[xx].find_by_order(l-1))+1;
            if(dist.find({x,yyy}) == dist.end()  ||  dist[{x,yyy}] > z)dist[{x,yyy}]=z, pq.emplace(make_tuple(-z,x,yyy));
        }
        if(l < (int)row[xx].size())
        {
            yyy=*(row[xx].find_by_order(l))-1;
            if(dist.find({x,yyy}) == dist.end()  ||  dist[{x,yyy}] > z)dist[{x,yyy}]=z, pq.emplace(make_tuple(-z,x,yyy));
        }

        ///same col er row gula
        l=col[yy].order_of_key(x);
        if(l)
        {
            xxx=*(col[yy].find_by_order(l-1))+1;
            if(dist.find({xxx,y}) == dist.end()  ||  dist[{xxx,y}] > z)dist[{xxx,y}]=z, pq.emplace(make_tuple(-z,xxx,y));
        }
        if(l < (int)col[yy].size())
        {
            xxx=*(col[yy].find_by_order(l))-1;
            if(dist.find({xxx,y}) == dist.end()  ||  dist[{xxx,y}] > z)dist[{xxx,y}]=z, pq.emplace(make_tuple(-z,xxx,y));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<int>X,Y;
    int cnt,i,q,gx,gy,sx,sy,x,y;
    cin >> n >> m >> q >> sx >> sy >> gx >> gy;
    X.insert(sx), X.insert(gx);
    Y.insert(sy), Y.insert(gy);
    for(i=0;i<q;i++)
    {
        cin >> x >> y, obstacles[i]={x, y};
        X.insert(x), Y.insert(y);
    }
    cnt=0;
    for(int it : X)rowMap[it]=++cnt;
    cnt=0;
    for(int it : Y)colMap[it]=++cnt;
    for(i=0;i<q;i++)
    {
        row[rowMap[obstacles[i].first]].insert(obstacles[i].second);
        col[colMap[obstacles[i].second]].insert(obstacles[i].first);
    }
    dist[{sx,sy}]=0, pq.emplace(make_tuple(0,sx,sy));
    Dijkstra();
    if(dist.find({gx,gy}) == dist.end())cout << "-1";
    else cout << dist[{gx,gy}];
    return 0;
}
