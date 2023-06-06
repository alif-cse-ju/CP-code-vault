
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
const int mod=1e9+7;

ll a[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; ll k;cin >> n >> k;
    set<pair<ll,int>>st;
    for(int i=1;i<=n;i++)cin >> a[i], st.insert({a[i],i});
    ll nichi=0;
    while(!st.empty()  &&  k >= (ll)st.size())
    {
        ll l=(ll)st.size();
        auto [x,i]=*(st.begin());
        ll neyajbe=min(x-nichi, k/l); k-=neyajbe*l, nichi+=neyajbe;
        while(!st.empty())
        {
            auto [y,j]=*(st.begin());
            if(y > nichi)break;
            st.erase(st.begin());
        }
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=max(0ll, a[i]-nichi);
        if(k  &&  a[i])--a[i], --k;
        cout << a[i] << ' ';
    }
    return 0;
}
