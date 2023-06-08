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
const int mod=1e9+7;
int n,cnt[20][N],dp[M+N],L[20],R[20];
int DP(int mask)
    if(__builtin_popcount(mask) == n)return 0;
    int &ans=dp[mask];
    if(ans != -1)return ans;
    int i,curL=0,tmp;
    for(i=0;i<n;i++)
    {
        if((mask >> i) & 1)curL += L[i]-R[i];
    }
    for(i=0;i<n;i++)
    {
        if(!((mask >> i) & 1))
        {
            tmp=0;
            if(curL >= 0)tmp += cnt[i][curL];
            if(R[i] <= curL)tmp += DP(mask | (1 << i));
            ans=max(ans,tmp);
        }
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i,l,r;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> s;
        l=r=0;
        for(char& c : s)
        {
            if(c == '(')++l;
            else if(l)
            {
                --l;
                if(!l)++cnt[i][r];
            }
            else ++r,++cnt[i][r];
        }
        L[i]=l, R[i]=r;
    }
    memset(dp,-1,sizeof(dp));
    cout << DP(0);
    return 0;
}