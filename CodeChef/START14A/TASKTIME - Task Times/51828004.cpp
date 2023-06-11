#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int c[M];
deque<int>dq[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,k,m,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        for(i=1;i<=m;i++)dq[i].clear();
        for(i=1;i<=n;i++)cin >> c[i];
        for(i=1;i<=n;i++)
        {
            cin >> x;
            dq[c[i]].emplace_back(x);
        }
        priority_queue<int>pq;
        for(i=1;i<=m;i++)
        {
            sort(dq[i].begin(),dq[i].end());
            if(!dq[i].empty())
            {
                pq.emplace(-dq[i].front());
                dq[i].pop_front();
                while((int)dq[i].size() >= 2)
                {
                    x=0;
                    x+=dq[i].front(),dq[i].pop_front();
                    x+=dq[i].front(),dq[i].pop_front();
                    pq.emplace(-x);
                }
            }
        }
        ans=0;
        while(!pq.empty())
        {
            x=-pq.top(),pq.pop();
            if(x > k)break;
            ++ans,k-=x;
        }
        cout << ans << '\n';
    }
    return 0;
}