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
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int ans,i,l,t;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        ans=INT_MAX;
        for(i=1;i<l  &&  ans == INT_MAX;i++)
        {
            if(s[i] == 'a'  &&  s[i-1] == 'a')ans=2;
        }
        for(i=2;i<l  &&  ans == INT_MAX;i++)
        {
            if(s[i] == 'a'  &&  s[i-2] == 'a')ans=3;
        }
        for(i=3;i<l  &&  ans == INT_MAX;i++)
        {
            if(s[i] == 'a'  &&  s[i-3] == 'a'  &&   ((s[i-2] == 'b'  &&  s[i-1] == 'c')  ||  (s[i-2] == 'c'  &&  s[i-1] == 'b')))ans=4;
        }
        for(i=6;i<l  &&  ans == INT_MAX;i++)
        {
            if(s[i] == 'a'  &&  s[i-3] == 'a'  &&  s[i-6] == 'a'  &&   ((s[i-5] == 'b'  &&  s[i-4] == 'b'  &&  s[i-2] == 'c'  &&  s[i-1] == 'c')  ||   (s[i-5] == 'c'  &&  s[i-4] == 'c'  &&  s[i-2] == 'b'  &&  s[i-1] == 'b')))ans=7;
        }
        if(ans == INT_MAX)ans=-1;
        cout << ans << '\n';
    }
    return 0;
}