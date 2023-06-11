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
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,n,t,x,B[5],G[5],R[5];
    cin >> t;
    while(t--)
    {
        ans=0;
        cin >> n;
        for(i=1;i<4;i++)cin >> R[i] >> G[i] >> B[i];
        x=min(G[1], R[2]), ans += x, G[1] -= x, R[2] -= x;
        x=min(B[1], R[3]), ans += x, B[1] -= x, R[3] -= x;
        x=min(B[2], G[3]), ans += x, B[2] -= x, G[3] -= x;
        ans += (G[1] + B[1]) * 2;
        cout << ans << '\n';
    }
    return 0;
}