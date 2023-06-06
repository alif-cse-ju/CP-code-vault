#pragma GCC optimize("Ofast")

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

const int M=3e5+5;
const int N=2e6+5;
const int mod=998244353;

ll val[M];
bool inSet[M];
int X[M],C[M],cnt[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=1;i<=n;i++)cin >> X[i], ++cnt[X[i]];
    set<pair<ll,int>>st;
    for(int i=1;i<=n;i++)
    {
        cin >> C[i];
        inSet[i]=1, val[i]=1ll*C[i]*cnt[i];
        st.insert({val[i], i});
    }
    ll ans=0;
    while(!st.empty())
    {
        auto [v,i]=*(st.begin());
        st.erase(st.begin()), inSet[i]=0, ans += v;
        if(inSet[X[i]])
        {
            st.erase({val[X[i]], X[i]});
            val[X[i]] -= C[X[i]];
            st.insert({val[X[i]], X[i]});
        }
    }
    cout << ans;
    return 0;
}
