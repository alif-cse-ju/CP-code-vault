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
int a[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,cnt1,cnt2,i,j,l,r,t;
    cin >> t;
    while(t--)
    {
        cin >> l >> r;
        for(i=l;i<=r;i++)cin >> a[i];
        ans=0;
        for(j=0;j<17;j++)
        {
            cnt1=cnt2=0;
            for(i=l;i<=r;i++)cnt1 += ((i >> j) & 1), cnt2 += ((a[i] >> j) & 1);
            if(cnt1 != cnt2)ans |= (1 << j);
        }
        cout << ans << '\n';
    }
    return 0;
}