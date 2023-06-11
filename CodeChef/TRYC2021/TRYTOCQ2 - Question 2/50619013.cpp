#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e4+5;
const int N=1e6+5;
const int mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string ss;
    int c=1,d=1,l,s=1,_s=1;
    cin >> l >> ss;
    for(char c : ss)
    {
        if(c >= '0'  &&  c <= '9')d=0;
        else if(c >= 'A'  &&  c <= 'Z')c=0;
        else if(c >= 'a'  &&  c <= 'z')s=0;
        else _s=0;
    }
    cout << max(6-l,c+d+s+_s);
    return 0;
}