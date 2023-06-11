#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
deque<int>pos[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int i,l,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        set<int>st;
        for(i=1;i<=n;i++)cin >> x, st.insert(x), pos[x].emplace_back(i);
        ans=0;
        for(int it : st)
        {
            pos[it].emplace_front(0), pos[it].emplace_back(n+1);
            l=(int)pos[it].size()-1;
            for(i=1;i+it<=l;i++)ans += 1ll*it*(pos[it][i]-pos[it][i-1])*(pos[it][i+it]-pos[it][i+it-1]);
            pos[it].clear();
        }
        cout << ans << '\n';
    }
    return 0;
}