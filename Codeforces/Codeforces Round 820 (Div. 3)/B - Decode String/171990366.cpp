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

const int M=5e5+5;
const int N=2e6+5;
const int mod=998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int l;cin >> l;
        string s;cin >> s;
        string ans="";
        for(int i=l-1;i>=0;i--)
        {
            if(s[i] != '0')ans += (char)('a'+(s[i]-'1'));
            else
            {
                int x=(s[i-2]-'0')*10 + (s[i-1]-'0');
                i -= 2, ans += (char)('a'+x-1);
            }
        }
        reverse(ans.begin(),ans.end());
        cout << ans << '\n';
    }
    return 0;
}
