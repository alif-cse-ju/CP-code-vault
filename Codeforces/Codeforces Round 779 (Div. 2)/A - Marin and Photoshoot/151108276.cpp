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
const int N=2e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int ans,i,l,t;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        ans=0;
        for(i=1;i<l;i++)
        {
            if(s[i] == '0'  &&  s[i-1] == '0')ans += 2;
            else if(i > 1  &&  s[i] == '0'  &&  s[i-1] == '1'  &&  s[i-2] == '0')ans += 1;
        }
        cout << ans << '\n';
    }
    return 0;
}