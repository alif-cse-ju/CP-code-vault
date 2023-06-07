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
const int M=1e5+5;
const int N=1e6+5;
const int mod=998244353;
int dp[(1 << 24)];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int ans,i,j,mask,n;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> s;
        mask=0;
        mask |= (1 << (s[0]-'a'));
        mask |= (1 << (s[1]-'a'));
        mask |= (1 << (s[2]-'a'));
        ++dp[mask];
    }
    for(i=0;i<24;i++)
    {
        for(j=0;j<(1 << 24);j++)
        {
            if((j >> i) & 1)dp[j] += dp[j ^ (1 << i)];
        }
    }
    ans=0;
    for(i=0;i<(1 << 24);i++)ans ^= (n-dp[i])*(n-dp[i]);
    cout << ans;
    return 0;
}