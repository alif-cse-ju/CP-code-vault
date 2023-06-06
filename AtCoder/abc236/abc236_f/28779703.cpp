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

const int sz=(1 << 16);

bool pos[sz];
pair<int,int>cost[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans=0;
    int i,j,k,l,mask,n;
    cin >> n;
    n=(1 << n);
    for(i=1;i<n;i++)cin >> cost[i].first, cost[i].second=i;
    sort(cost+1,cost+n);
    vector<int>v;
    for(i=1;i<n;i++)
    {
        mask=cost[i].second;
        if(pos[mask])continue;
        ans += cost[i].first;
        vector<int>vv;
        vv.emplace_back(mask);
        for(int it : v)vv.emplace_back(mask ^ it);
        for(int it : vv)v.emplace_back(it), pos[it]=1;
    }
    cout << ans;
    return 0;
}