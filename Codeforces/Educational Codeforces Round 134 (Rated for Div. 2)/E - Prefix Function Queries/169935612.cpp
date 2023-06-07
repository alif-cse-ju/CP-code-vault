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
const int M=2e5+5;
const int N=1e6+20;
const int mod=1e9+7;
int dp[N][26];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;cin >> s;
    dp[0][s[0]-'a']=1;
    int l=(int)s.size(), lps=0;
    for(int i=1;i<l;i++)
    {
        for(int j=0;j<26;j++)dp[i][j]=dp[lps][j];
        dp[i][s[i]-'a']=i+1, lps=dp[lps][s[i]-'a'];
    }
    int q;cin >> q;
    while(q--)
    {
        string ss;cin >> ss;
        int l2=(int)ss.size(), lpsN=lps;
        for(int i=l;i<l+l2;i++)
        {
            for(int j=0;j<26;j++)dp[i][j]=dp[lpsN][j];
            dp[i][ss[i-l]-'a']=i+1, lpsN=dp[lpsN][ss[i-l]-'a'];
            cout << lpsN << ' ';
        }
        cout << '\n';
    }
    return 0;
}