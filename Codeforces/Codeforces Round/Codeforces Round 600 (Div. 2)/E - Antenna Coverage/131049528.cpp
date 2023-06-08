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
const int N=2e6+5;
const int mod=1e9+7;
int cnt[M],dp[M],X[82],S[82];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,m,n;
    cin >> n >> m;
    for(i=1;i<=n;i++)
    {
        cin >> X[i] >> S[i];
        ++cnt[max(1,X[i]-S[i])], --cnt[min(m,X[i]+S[i])+1];
    }
    for(i=2;i<=m;i++)cnt[i] += cnt[i-1];
    for(i=m;i;i--)
    {
        if(cnt[i])dp[i]=dp[i+1];
        else
        {
            dp[i]=m-i+1;
            for(j=1;j<=n;j++)
            {
                if(X[j]-S[j] > i)dp[i]=min(dp[i],X[j]-S[j]-i+dp[min(m,2*X[j]-i)+1]);
            }
        }
    }
    cout << dp[1];
    return 0;
}