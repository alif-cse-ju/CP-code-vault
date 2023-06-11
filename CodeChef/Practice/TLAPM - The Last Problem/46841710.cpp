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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    long long x,x1,x2,y1,y2,ans,val;
    cin >> t;
    while(t--)
    {
        ans=0;
        cin >> x1 >> y1 >> x2 >> y2;
        for(x1=x1;x1<=x2;x1++)x=x1+y1-2,val=(x*(x+1))/2,ans+=val+x1;
        for(y1=y1+1;y1<=y2;y1++)x=x2+y1-2,val=(x*(x+1))/2,ans+=val+x2;
        cout << ans << '\n';
    }
    return 0;
}