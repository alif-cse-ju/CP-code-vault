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
const int mod=1e9+7;
int a[3][M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<3;i++)
        {
            for(j=1;j<=n;j++)cin >> a[i][j],a[i][j]+=a[i][j-1];
        }
        ans=INT_MAX;
        for(i=n;i;i--)ans=min(ans,max(a[1][n]-a[1][i],a[2][i-1]));
        cout << ans << '\n';
    }
    return 0;
}