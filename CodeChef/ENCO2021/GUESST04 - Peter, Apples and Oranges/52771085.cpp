#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
char ans[N];
void Build(int nodeNum,int lvl,char c)
{
    ans[nodeNum]=c;
    if(lvl == 20)return;
    if(c == 'A')
    {
        Build(2*nodeNum,lvl+1,'A');
        Build(2*nodeNum+1,lvl+1,'O');
    }
    else
    {
        Build(2*nodeNum,lvl+1,'O');
        Build(2*nodeNum+1,lvl+1,'A');
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,n,t;
    Build(1,1,'A');
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        n=(1 << (n-1))-1;
        cout << ans[n+k] << '\n';
    }
    return 0;
}