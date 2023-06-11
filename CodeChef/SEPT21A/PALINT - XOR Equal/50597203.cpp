#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e4+5;
const int N=1e6+5;
const int mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,x,X;
    cin >> t;
    while(t--)
    {
        cin >> n >> X;
        map<int,int>mp;
        while(n--)cin >> x,++mp[x];
        if(!X)
        {
            priority_queue<int>pq;
            for(auto [x,y] : mp)pq.emplace(y);
            cout << pq.top() << " 0\n";
        }
        else
        {
            priority_queue<pair<int,int>>pq;
            for(auto [x,y] : mp)pq.emplace(y+mp[x ^ X],-mp[x ^ X]);
            cout << pq.top().first << ' ' << -pq.top().second << '\n';
        }
    }
    return 0;
}