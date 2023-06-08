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
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[5005];
int DP(int l,int r)
    if(l > r)return 0;
    int i,idx=l;
    for(i=l;i<=r;i++)
    {
        if(a[i] < a[idx])idx=i;
    }
    return min(r-l+1,DP(l,idx-1)+DP(idx+1,r)+a[idx]-max(a[l-1],a[r+1]));
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    cout << DP(1,n);
    return 0;
}