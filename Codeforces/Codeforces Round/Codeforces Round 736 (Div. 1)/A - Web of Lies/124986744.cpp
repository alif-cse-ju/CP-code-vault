#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
ordered_set<int>adj[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans=0,c,i,m,n,q,x,y;
    cin >> n >> m;
    while(m--)
    {
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    for(i=1;i<=n;i++)ans+=(int)adj[i].size() == adj[i].order_of_key(i);
    cin >> q;
    while(q--)
    {
        cin >> c;
        if(c == 1)
        {
            cin >> x >> y;
            if(x > y)swap(x,y);
            if((int)adj[x].size() == adj[x].order_of_key(x))--ans;
            adj[x].insert(y),adj[y].insert(x);
        }
        else if(c == 2)
        {
            cin >> x >> y;
            if(x > y)swap(x,y);
            adj[x].erase(adj[x].find_by_order(adj[x].order_of_key(y)));
            adj[y].erase(adj[y].find_by_order(adj[y].order_of_key(x)));
            if((int)adj[x].size() == adj[x].order_of_key(x))++ans;
        }
        else cout << ans << '\n';
    }
    return 0;
}