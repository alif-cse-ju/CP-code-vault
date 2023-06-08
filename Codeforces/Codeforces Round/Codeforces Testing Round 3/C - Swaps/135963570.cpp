#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,s,x;
    vector<pair<int,int>>ans,v;
    priority_queue<pair<int,int>>pq;
    cin >> n >> s;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        if(x)pq.emplace(x,i);
    }
    while(!pq.empty())
    {
        auto [x,i]=pq.top();
        pq.pop();
        while(x > 0)
        {
            if(pq.empty())
            {
                cout << "No";
                return 0;
            }
            auto [y,j]=pq.top();
            pq.pop();
            --x, --y;
            ans.emplace_back(i,j);
            if(y)v.emplace_back(y,j);
        }
        while(!v.empty())pq.emplace(v.back()), v.pop_back();
    }
    cout << "Yes\n" << (int)ans.size() << '\n';
    for(auto [x,y] : ans)cout << x << ' ' << y << '\n';
    return 0;
}