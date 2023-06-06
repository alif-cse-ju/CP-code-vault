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

const int M=1e5+5;
const int N=2e6+5;
const int mod=998244353;

int child[M],parent[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,q,x,y;
    cin >> n >> q;
    while(q--)
    {
        cin >> t;
        if(t == 1)cin >> x >> y, child[x]=y, parent[y]=x;
        else if(t == 2)cin >> x >> y, child[x]=parent[y]=0;
        else
        {
            cin >> x;
            y=parent[x];
            while(y)x=y, y=parent[x];
            vector<int>ans;
            while(x)ans.emplace_back(x), x=child[x];
            cout << (int)ans.size();
            for(int it : ans)cout << ' ' << it;
            cout << '\n';
        }
    }
    return 0;
}