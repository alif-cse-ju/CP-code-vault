#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=1e6+5;
const int mod=1e9+7;
const int mx = 4e3;
const int sz = mx+mx;
ll dp[sz+mx+2];
int A[M],T[M],X[M],Y[M];
ordered_set<int>ost[sz+2];
vector<int>in[sz+2],out[sz+2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=1;i<=n;i++)cin >> T[i];
    for(int i=1;i<=n;i++)cin >> X[i];
    for(int i=1;i<=n;i++)cin >> Y[i];
    for(int i=1;i<=n;i++)cin >> A[i];
    for(int i=1;i<=n;i++)
    {
        out[T[i]].emplace_back(i);
        in[T[i]+Y[i]].emplace_back(i);
    }
    for(int i=sz;i;i--)
    {
        dp[i]=dp[i+1];
        for(int it : in[i])ost[X[it]].insert(A[it]);
        for(int j=mx;j;j--)
        {
            if(ost[j].empty())continue;
            dp[i]=max(dp[i], dp[i+j] + *(--ost[j].end()));
        }
        for(int it : out[i])ost[X[it]].erase(ost[X[it]].find_by_order(ost[X[it]].order_of_key(A[it])));
    }
    cout << dp[1];
    return 0;
}