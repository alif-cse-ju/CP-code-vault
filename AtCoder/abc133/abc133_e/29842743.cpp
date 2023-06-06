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

ll k;
vector<int>adj[M];

ll DFS(int x,int p)
{
    bool ok=0;
    ll ans=1,tmp;
    int i,l=(int)adj[x].size(),rem,y;
    for(i=0;i<l;i++)
    {
        y=adj[x][i];
        if(p ^ y)
        {
            rem=k-i-(p > 0)-1+ok;
            if(rem < 1)ans=0;
            else tmp=(rem * DFS(y, x))%mod, ans=(ans * tmp)%mod;
        }
        else ok=1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,x,y;
    cin >> n >> k;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    cout << (DFS(1, 0)*k)%mod;
    return 0;
}