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
const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;
const int sz = 5e3+5;
int dp[sz],par[sz];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,H,i,j,mx=0,n,start,w,W;
    cin >> n >> W >> H;
    vector<tuple<int,int,int>>v;
    for(i=1;i<=n;i++)
    {
        cin >> w >> h;
        if(w > W  &&  h > H)v.emplace_back(make_tuple(w,h,i));
    }
    if(v.empty())
    {
        cout << "0";
        return 0;
    }
    v.emplace_back(make_tuple(W,H,0));
    sort(v.begin(),v.end());
    n=(int)v.size();
    for(i=1;i<n;i++)
    {
        auto [x,y,ii]=v[i];
        dp[i]=1;
        for(j=i-1;j;j--)
        {
            auto [x1,y1,jj]=v[j];
            if(x1 < x  &&  y1 < y  &&  dp[i] < dp[j]+1)dp[i]=dp[j]+1, par[i]=j;
        }
        if(dp[i] > mx)mx=dp[i], start=i;
    }
    vector<int>ans;
    while(start)ans.emplace_back(get<2>(v[start])), start=par[start];
    cout << (int)ans.size() << '\n';
    while(!ans.empty())cout << ans.back() << ' ', ans.pop_back();
    return 0;
}