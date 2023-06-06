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
const int N=1e6+5;
const int mod=998244353;

int a[M];
vector<int>adj[M];
ordered_set<int>ost;

int DFS(int x,int p,bool coin)
{
    vector<int>ans;
    ost.insert(a[x]);
    if(x > 1  &&  (int)adj[x].size() == 1)
    {
        int l=(int)ost.size();
        if(l & 1)ans.emplace_back(*(ost.find_by_order(l/2)));
        else ans.emplace_back((*(ost.find_by_order(l/2-1)) + *(ost.find_by_order(l/2))) / 2);
    }
    else
    {
        for(int y : adj[x])
        {
            if(p ^ y)ans.emplace_back(DFS(y,x,1-coin));
        }
    }
    ost.erase(ost.find_by_order(ost.order_of_key(a[x])));
    sort(ans.begin(),ans.end());
    if(coin)return ans.back();
    return ans[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,x,y;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    cout << DFS(1,0,1);
    return 0;
}
