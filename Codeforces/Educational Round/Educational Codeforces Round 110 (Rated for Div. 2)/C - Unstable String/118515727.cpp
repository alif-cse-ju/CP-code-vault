#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
char s[N];
int dp[N][2];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,t,x,y;
    long long ans;
    cin >> t;
    while(t--)
    {
        cin >> s+1;
        l=strlen(s+1);
        ans=l;
        for(i=1;i<=l;i++)
        {
            dp[i][0]=dp[i][1]=0;
            if(s[i] == '0')
            {
                if(!dp[i-1][1])dp[i][0]=i;
                else ans+=i-dp[i-1][1],dp[i][0]=dp[i-1][1];
            }
            else if(s[i] == '1')
            {
                if(!dp[i-1][0])dp[i][1]=i;
                else ans+=i-dp[i-1][0],dp[i][1]=dp[i-1][0];
            }
            else
            {
                x=y=0;
                if(!dp[i-1][1])dp[i][0]=i;
                else x=i-dp[i-1][1],dp[i][0]=dp[i-1][1];
                if(!dp[i-1][0])dp[i][1]=i;
                else y=i-dp[i-1][0],dp[i][1]=dp[i-1][0];
                ans+=max(x,y);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}