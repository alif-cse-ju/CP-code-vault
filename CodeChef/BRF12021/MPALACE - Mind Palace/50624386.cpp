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
const int M=1e5+5;
const int N=1e6+5;
const int mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<deque<int>>v;
        priority_queue<pair<int,int>>pq;
        for(i=0;i<n;i++)
        {
            cin >> m;
            deque<int>dq;
            while(m--)cin >> x,dq.emplace_back(x);
            pq.emplace(-dq.front(),i);
            dq.pop_front();
            v.emplace_back(dq);
        }
        vector<int>ans;
        while(!pq.empty())
        {
            auto [x,y]=pq.top();
            pq.pop();
            ans.emplace_back(-x);
            if(!v[y].empty())
            {
                pq.emplace(-v[y].front(),y);
                v[y].pop_front();
            }
        }
        for(int it : ans)cout << it << ' ';
        cout << '\n';
    }
    return 0;
}