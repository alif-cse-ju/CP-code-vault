#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
char s[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,q,t,x,ans;
    cin >> t;
    while(t--)
    {
        cin >> l >> q >> s+1;
        ans=l-1;
        for(i=2;i<=l;i++)ans+=(s[i] == s[i-1]);
        while(q--)
        {
            cin >> x;
            if(s[x] == '0')s[x]='1';
            else s[x]='0';
            if(x-1)
            {
                if(s[x-1] != s[x])--ans;
                else ++ans;
            }
            if(x+1 <= l)
            {
                if(s[x+1] != s[x])--ans;
                else ++ans;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}