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
ll v[M],pre[M],suf[M],preAns[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=1;i<=n;i++)cin >> v[i];
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+v[i];
    for(int i=n;i;i--)suf[i]=suf[i+1]+v[i];
    map<ll,int>mp;
    ordered_set<pair<ll,int>>ost;
    for(int i=1;i<=n;i++)
    {
        ll tmp=max(0ll, v[i]-preAns[i-1]-(preAns[i-1]*(i-1)-pre[i-1]));
        preAns[i]=preAns[i-1] + (tmp+i-1)/i;
         tmp=max(0ll, suf[i+1]-(preAns[i]*i - pre[i]));
         tmp = preAns[i]+(tmp+i-1)/i;
        if(mp.find(tmp) == mp.end())mp[tmp]=i;
    }
     for(auto [v,i] : mp)ost.insert({v,i});
     int q;cin >> q;
    while(q--)
    {
        ll x;cin >> x;
        int l=ost.order_of_key({x,n+1});
        if(!l)cout << "-1\n";
        else
        {
            auto [v,need]=*(ost.find_by_order(l-1));
            cout << need << '\n';
        }
    }
    return 0;
}