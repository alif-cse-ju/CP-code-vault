#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> a(n);
    for (auto &[x, y] : a) scanf("%d %d", &x, &y);
    set<pair<int, int>> st(a.begin(), a.end());
    map<pair<int, int>, pair<int, int>> ans;
    queue<pair<int, int>> q;
    for(auto [x, y] : a)
    {
        for(int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(st.count({nx, ny}))continue;
            ans[{x, y}] = {nx, ny};
            q.push({x, y});
            break;
        }
    }
     while(!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (!st.count({nx, ny}) || ans.count({nx, ny}))continue;
            ans[{nx, ny}] = ans[{x, y}];
            q.push({nx, ny});
        }
    }
     for(auto [x, y] : a)
    {
        auto it = ans[{x, y}];
        printf("%d %d\n", it.first, it.second);
    }
    return 0;
}