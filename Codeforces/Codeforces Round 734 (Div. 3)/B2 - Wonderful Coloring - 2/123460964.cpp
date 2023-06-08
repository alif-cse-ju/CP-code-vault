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
const int N=2e5+5;
const int mod=1e9+7;
int ans[N];
vector<int>pos[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)cin >> x,pos[x].emplace_back(i);
        vector<int>v;
        for(i=1;i<=n;i++)
        {
            while((int)pos[i].size() > k)pos[i].pop_back();
            while(!pos[i].empty())v.emplace_back(pos[i].back()),pos[i].pop_back();
        }
        while((int)v.size()%k)v.pop_back();
        for(i=1;i<=n;i++)ans[i]=0;
        for(i=0;i<(int)v.size();i++)ans[v[i]]=i%k+1;
        for(i=1;i<=n;i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}