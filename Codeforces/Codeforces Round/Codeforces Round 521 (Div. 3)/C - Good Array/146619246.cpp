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
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=2e6+5;
const int mod=998244353;
int cnt[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ll sum=0;
    cin >> n;
    vector<int>v(n);
    for(int &x : v)cin >> x, sum+=x, ++cnt[x];
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        sum-=v[i], --cnt[v[i]];
        if(sum%2 == 0  &&  sum <= N  &&  cnt[sum/2])ans.emplace_back(i+1);
        sum+=v[i], ++cnt[v[i]];
    }
    cout << (int)ans.size() << '\n';
    for(int &x : ans)cout << x << ' ';
    return 0;
}