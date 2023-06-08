#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=998244353;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    bool _0,_1;
    int i,l,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> l >> a >> b;
        ans=_0=_1=0;
        for(i=0;i<l;i++)
        {
            if(a[i] != b[i])
            {
                if(_0)++ans;
                ans+=2,_0=_1=0;
            }
            else
            {
                if(a[i] == '1')
                {
                    if(_0)ans+=2,_0=0;
                    else _1=1;
                }
                else
                {
                    if(_1)ans+=2,_1=0;
                    else
                    {
                        if(_0)++ans;
                        else _0=1;
                    }
                }
            }
        }
        if(_0)++ans;
        cout << ans << '\n';
    }
    return 0;
}