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
const int N=1e6+5;
const int mod=1e9+7;

int ans[M],par[M];
vector<int>adj[M];

int Par(int p)
{
    if(par[p] == p)return p;
    return par[p]=Par(par[p]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt=0,i,m,n,x,y;
    cin >> n >> m;
    for(i=1;i<=n;i++)par[i]=i;
    while(m--)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
    }
    for(i=n;i;i--)
    {
        ans[i]=cnt;
        set<int>st;
        for(int it : adj[i])
        {
            x=Par(it);
            if(x != i)par[x]=i, st.insert(x);
        }
        cnt += 1-(int)st.size();
    }
    for(i=1;i<=n;i++)cout << ans[i] << '\n';
    return 0;
}
