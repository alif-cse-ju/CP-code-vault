#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;
int a[M], b[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i], b[i]=a[i];
    sort(b+1,b+n+1);
    int ans=(b[1]+1)/2 + (b[2]+1)/2;
    for(int i=2;i<n;i++)ans=min(ans, (a[i-1] + a[i+1] +1)/2);
    for(int i=2;i<=n;i++)
    {
        int x=min(a[i], a[i-1]);
        int y=max(a[i], a[i-1]);
        if(x+x <= y)ans=min(ans, (y+1)/2);
        else ans=min(ans, (x+y+2)/3);
    }
    cout << ans;
    return 0;
}