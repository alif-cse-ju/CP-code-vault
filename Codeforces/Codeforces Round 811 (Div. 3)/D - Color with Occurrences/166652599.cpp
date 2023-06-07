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
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        string s;cin >> s;
        int l=(int )s.size();
        vector<int>dp(l+5,0),nxt(l+5),used(l+5);
        for(int i=l-1;i>=0;i--)dp[i]=1000;
        int n;cin >> n;
        vector<string>v(n);
        for(string &ss : v)cin >> ss;
        nxt[l]=l;
        for(int i=l-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                int lv=(int)v[j].size();
                if(i+lv <= l  &&  s.substr(i,lv) == v[j])
                {
                    int mn=200,id=l;
                    for(int k=i+1;k<=i+lv;k++)
                    {
                        if(dp[k] < mn)mn=dp[k], id=k;
                    }
                    if(mn+1 < dp[i])dp[i]=mn+1, nxt[i]=id, used[i]=j;
                }
            }
        }
        if(dp[0] > l)cout << "-1\n";
        else
        {
            cout << dp[0] << '\n';
            int i=0;
            while(i < l)cout << used[i]+1 << ' ' << i+1 << '\n', i=nxt[i];
        }
    }
    return 0;
}