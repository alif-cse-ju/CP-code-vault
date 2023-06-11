#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=5e5+5;
const int N=2e6+5;
const int mod=1e9+7;
ll temp[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    string s;
    int close,i,l,open,t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        l=(int)s.size();
        open=close=0;
        for(char c : s)
        {
            if(c == '(')++open;
            else ++close, temp[close]=open+temp[close-1];
        }
        ans=LLONG_MAX, open=close=0;
        for(char c : s)
        {
            if(open < l/2)ans=min(ans, temp[open+1]-temp[close]-1ll*open*(open-close+1));
            if(c == '(')++open;
            else ++close;
        }
        cout << ans << '\n';
    }
    return 0;
}