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
const int mx = 32768;
int dp[mx+5];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1;i<mx;i++)dp[i]=20;
    for(int i=1;i<16;i++)
    {
        for(int j=1;j<mx;j++)
        {
            if(dp[j] == 20  &&  (dp[j+1] == i-1  ||  dp[(j+j)%mx] == i-1))dp[j]=i;
        }
    }
    while(n--)
    {
        int x;
        cin >> x;
        cout << dp[x] << ' ';
    }
    return 0;
}