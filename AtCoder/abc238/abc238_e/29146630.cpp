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

bool visited[M];
vector<int>adj[M];

void DFS(int x)
{
    if(visited[x])return;
    visited[x]=1;
    for(int y : adj[x])DFS(y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l,n,q,r;
    cin >> n >> q;
    while(q--)
    {
        cin >> l >> r;
        adj[l-1].emplace_back(r);
        adj[r].emplace_back(l-1);
    }
    DFS(0);
    if(visited[n])cout << "Yes";
    else cout << "No";
    return 0;
}