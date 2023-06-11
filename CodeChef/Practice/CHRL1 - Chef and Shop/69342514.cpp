#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int k,n;cin >> n >> k;
        vector<int>cost(n), weight(n);
        for(int i=0;i<n;i++)cin >> cost[i] >> weight[i];
        int l=(1 << n), maxWeight=0;
        for(int mask=0;mask<l;mask++)
        {
            int tCost=0, tWeight=0;
            for(int i=0;i<n;i++)
            {
                if((mask >> i) & 1)tCost+=cost[i], tWeight+=weight[i];
            }
            if(tCost <= k)maxWeight=max(maxWeight, tWeight);
        }
        cout << maxWeight << '\n';
    }
    return 0;
}