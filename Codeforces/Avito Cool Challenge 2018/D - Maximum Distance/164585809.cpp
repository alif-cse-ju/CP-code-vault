#pragma GCC optimize("Ofast")

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

int par[M];

int FindParent(int n)
{
    if(par[n] == n)return n;
    return par[n]=FindParent(par[n]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,m,n;cin >> n >> m >> k;
    vector<int>special(k);
    for(int &x : special)cin >> x;
    vector<tuple<int,int,int>>edges;
    while(m--)
    {
        int x,y,z;cin >> x >> y >> z;
        edges.emplace_back(make_tuple(z,x,y));
    }
    int l=1, r=1000000000;
    sort(edges.begin(),edges.end());
    while(l <= r)
    {
        int m=(l+r) >> 1;
        for(int i=1;i<=n;i++)par[i]=i;
        for(auto [z,x,y] : edges)
        {
            if(z > m)break;
            int px=FindParent(x);
            int py=FindParent(y);
            if(px != py)par[py]=px;
        }
        set<int>st;
        for(int &x : special)st.insert(FindParent(x));
        if((int)st.size() == 1)r=m-1;
        else l=m+1;
    }
    for(int i=0;i<k;i++)cout << r+1 << ' ';
    return 0;
}