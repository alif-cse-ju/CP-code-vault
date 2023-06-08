#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
const int MX = 1e8+5;
int par[52];
bool queryIdx[MX];
ll boro,boroSum,choto,chotoSum;
vector<tuple<int,int,int>>edges;
void Reset(const int& n)
    boro=boroSum=choto=chotoSum=0;
    for(int i=1;i<=n;i++)par[i]=i;
int FindPar(int x)
    if(par[x] == x)return x;
    return par[x]=FindPar(par[x]);
}
 void Process(const int& n,const int& mid)
{
    Reset(n);
    vector<tuple<int,int,int,int>>tempEdges;
    for(auto [z,x,y] : edges)tempEdges.emplace_back(make_tuple(abs(mid-z),x,y,z));
    sort(tempEdges.begin(),tempEdges.end());
     int px,py;
    for(auto [zz,x,y,z] : tempEdges)
    {
        px=FindPar(x), py=FindPar(y);
        if(px != py)
        {
            par[px]=py;
            if(z > mid)++boro, boroSum += z;
            else ++choto, chotoSum += z;
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,l,m,n;
    vector<int>midPoints;
    ll a,ans=0,b,c,k,p,q,temp,x,y,z;
      cin >> n >> m;
    for(i=0;i<m;i++)
    {
        cin >> x >> y >> z;
        edges.emplace_back(make_tuple(z,x,y));
    }
    sort(edges.begin(),edges.end());
    Process(n,0);
     for(i=0;i<m;i++)
    {
        auto [z1,x1,y1]=edges[i];
        midPoints.emplace_back(z1);
        for(j=i+1;j<m;j++)
        {
            auto [z2,x2,y2]=edges[j];
            midPoints.emplace_back((z1+z2)/2);
            midPoints.emplace_back((z1+z2)/2 + 1);
        }
    }
     cin >> p >> k >> a >> b >> c;
    for(i=0;i<p;i++)cin >> q, queryIdx[q] ^= 1;
    for(i=p;i<k;i++)q=(a*q+b)%c, queryIdx[q] ^= 1;
     vector<int>queries;
    for(i=0;i<MX;i++)
    {
        if(queryIdx[i])queries.emplace_back(i);
    }
    i=0, l=(int)queries.size();
     midPoints.emplace_back(c);
    sort(midPoints.begin(),midPoints.end());
    for(int m : midPoints)
    {
        while(i < l  &&  queries[i] < m)
        {
            temp=choto*queries[i]-chotoSum + boroSum-boro*queries[i];
            ans ^= temp, ++i;
        }
        Process(n,m);
    }
    cout << ans;
    return 0;
}