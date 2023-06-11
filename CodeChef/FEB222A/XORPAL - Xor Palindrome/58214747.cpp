#pragma GCC optimize("Ofast")
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
const int M=1e5+5;
const int N=2e6+5;
const int mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int l,t,_0,_1;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        if(l & 1)cout << "YES\n";
        else
        {
            _0=_1=0;
            for(char c : s)
            {
                if(c == '0')++_0;
                else ++_1;
            }
            if((_0 & 1)  &&  _0 != _1)cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}