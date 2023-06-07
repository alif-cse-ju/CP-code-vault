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
const int N=2e6+5;
const int mod=1e9+7;
bool Solve()
    int i,n;
    ll x,y,sum=0;
    map<ll,int>mp;
    priority_queue<ll>pq;
    cin >> n;
    for(i=0;i<n;i++)cin >> x, sum += x, ++mp[x];
    pq.emplace(sum);
    while(!pq.empty()  &&  (int)pq.size() <= n)
    {
        x=pq.top(), pq.pop();
        if(mp[x] > 0)--mp[x];
        else
        {
            if(x%2)pq.emplace(x/2), pq.emplace((x/2)+1);
            else pq.emplace(x/2), pq.emplace(x/2);
        }
    }
    return pq.empty();
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        if(Solve())cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}