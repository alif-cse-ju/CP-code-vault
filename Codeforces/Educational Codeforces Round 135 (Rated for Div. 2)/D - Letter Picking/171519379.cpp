#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)
#define ll long long

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=3e5+5;
const int N=2e6+5;
const int mod=998244353;

const int sz = 2e3+5;

char s[sz];
int dp[sz][sz];

int Check(int l,int r)
{
    if(s[l] < s[r])return 1;
    if(s[l] > s[r])return 2;
    return 0;
}

int DP(int l,int r)
{
    if(l+1 == r)return (s[l] != s[r]);
    int &ans=dp[l][r];
    if(ans > -1)return ans;
    int dp1=DP(l+2,r), dp2=DP(l+1,r-1), dp3=DP(l,r-2);
    if((dp2 == 1  ||  (!dp2  &&  Check(l,r)))  &&  ((dp1 == 1  ||  (!dp1  &&  Check(l,l+1) == 1))  ||  (dp3 == 1  ||  (!dp3  &&  Check(r,r-1) == 1))))return ans=1;
    return ans=0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        cin >> s+1;
        int l=strlen(s+1);
        for(int i=1;i<=l;i++)
        {
            for(int j=i;j<=l;j++)dp[i][j]=-1;
        }
        int ans=DP(1,l);
        if(!ans)cout << "Draw\n";
        else if(ans == 1)cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}
