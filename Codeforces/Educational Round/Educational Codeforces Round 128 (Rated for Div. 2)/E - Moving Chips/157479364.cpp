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
int dp[3][M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int l;cin >> l;
        string s1,s2;cin >> s1 >> s2;
        while(!s1.empty()  &&  s1.back() == '.'  &&  s2.back() == '.')s1.pop_back(), s2.pop_back();
        reverse(s1.begin(),s1.end()), reverse(s2.begin(),s2.end());
        while(!s1.empty()  &&  s1.back() == '.'  &&  s2.back() == '.')s1.pop_back(), s2.pop_back();
        reverse(s1.begin(),s1.end()), reverse(s2.begin(),s2.end());
        l=(int)s1.size();
        s1="#"+s1, s2="#"+s2;
        dp[1][1]=(s2[1] == '*');
        dp[2][1]=(s1[1] == '*');
        for(int i=2;i<=l;i++)
        {
            dp[1][i]=dp[1][i-1]+1+(s2[i] == '*');
            dp[1][i]=min(dp[1][i], dp[2][i-1]+2);
             dp[2][i]=dp[2][i-1]+1+(s1[i] == '*');
            dp[2][i]=min(dp[2][i], dp[1][i-1]+2);
        }
        cout << min(dp[1][l], dp[2][l]) << '\n';
    }
    return 0;
}