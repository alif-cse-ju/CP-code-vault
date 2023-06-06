#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
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

int par[M];
bool ans[M];

int FindParent(int n)
{
    if(par[n] == n)return n;
    return par[n]=FindParent(par[n]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,px,py,q,x,y,z;
    cin >> n >> m >> q;
    for(i=1;i<=n;i++)par[i]=i;
    vector<tuple<int,int,int,int>>edges;
    while(m--)
    {
        cin >> x >> y >> z;
        edges.emplace_back(make_tuple(z,x,y,0));
    }
    for(i=1;i<=q;i++)
    {
        cin >> x >> y >> z;
        edges.emplace_back(make_tuple(z,x,y,i));
    }
    sort(edges.begin(),edges.end());
    for(auto [z,x,y,id] : edges)
    {
        px=FindParent(x);
        py=FindParent(y);
        if(id)
        {
            if(px != py)ans[id]=1;
            else ans[id]=0;
        }
        else
        {
            if(px != py)par[py]=px;
        }
    }
    for(i=1;i<=q;i++)
    {
        if(ans[i])cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
