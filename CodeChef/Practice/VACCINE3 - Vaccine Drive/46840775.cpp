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
    int g,i,p,t,a[12]={0};
    cin >> t;
    while(t--)
    {
        cin >> g >> p;
        for(i=1;i<11;i++)cin >> a[i];
        reverse(a+1,a+11),g=11-g;
        for(i=2;i<11;i++)a[i]+=a[i-1];
        cout << a[g-1]/p+1 << ' ' << (a[g]+p-1)/p << '\n';
    }
    return 0;
}