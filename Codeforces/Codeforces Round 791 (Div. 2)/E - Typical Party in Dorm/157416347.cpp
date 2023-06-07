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
const int sz = 1e3+5;
char s[sz];
ll dp[20][(1<<17)+5],power[sz];
int neededMask[sz][sz],questionCnt[sz][sz];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int len;cin >> len >> s+1;
    for(int i=len;i;i--)
    {
        for(int j=i+1;j<=len;j++)
        {
            neededMask[i][j]=neededMask[i+1][j-1];
            if(neededMask[i][j] == -1)continue;
            questionCnt[i][j]=questionCnt[i+1][j-1];
            if(s[i] == s[j])
            {
                if(s[i] == '?')++questionCnt[i][j];
            }
            else
            {
                if(s[i] == '?')neededMask[i][j]|=(1 << (s[j]-'a')), ++questionCnt[i][j];
                else if(s[j] == '?')neededMask[i][j]|=(1 << (s[i]-'a')), ++questionCnt[i][j];
                else neededMask[i][j]=-1;
            }
        }
    }
    power[0]=1;
    int totalQuestion=0;
    for(int i=1;i<=len;i++)totalQuestion += (s[i] == '?');
    for(int queryLen=1;queryLen<=17;queryLen++)
    {
        for(int i=1;i<sz;i++)power[i]=(power[i-1]*queryLen)%mod;
        for(int i=1;i<=len;i++)
        {
            for(int j=i;j<=len;j++)
            {
                if(neededMask[i][j] == -1)continue;
                dp[queryLen][neededMask[i][j]] += power[totalQuestion-questionCnt[i][j]];
                if(dp[queryLen][neededMask[i][j]] >= mod)dp[queryLen][neededMask[i][j]] -= mod;
            }
        }
        for(int i=0;i<17;i++)
        {
            for(int mask=1;mask<(1<<17);mask++)
            {
                if((mask >> i) & 1)
                {
                    dp[queryLen][mask] += dp[queryLen][mask ^ (1<<i)];
                    if(dp[queryLen][mask] >= mod)dp[queryLen][mask] -= mod;
                }
            }
        }
    }
    int q;cin >> q;
    while(q--)
    {
        string s;cin >> s;
        int mask=0;
        for(char &c : s)mask |= (1 << (c-'a'));
        cout << dp[__builtin_popcount(mask)][mask] << '\n';
    }
    return 0;
}