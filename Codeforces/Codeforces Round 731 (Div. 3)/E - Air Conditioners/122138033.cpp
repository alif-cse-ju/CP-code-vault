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
const int M=1e5+5;
const int N=3e5+5;
const int mod=1e9+7;
int n,a[N],ans[N];
priority_queue<pair<int,int>>pq;
void Dijkstra()
    int val,x;
    while(!pq.empty())
    {
        val=-pq.top().first;
        x=pq.top().second;
        pq.pop();
        if(ans[x] > val)
        {
            ans[x]=val;
            if(x < n)pq.emplace(-val-1,x+1);
            if(x > 1)pq.emplace(-val-1,x-1);
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=k;i++)cin >> a[i];
        for(i=1;i<=k;i++)
        {
            cin >> x;
            pq.emplace(-x,a[i]);
        }
        for(i=1;i<=n;i++)ans[i]=INT_MAX;
        Dijkstra();
        for(i=1;i<=n;i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}