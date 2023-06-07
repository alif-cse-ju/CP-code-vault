#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int a[M],b[M],n;
bool Check(int val)
    int cnt=val;
    for(int i=1;i<=n  &&  cnt;i++)
    {
        if(b[i] >= val-cnt  &&  a[i] >= cnt-1)--cnt;
    }
    return (cnt == 0);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,m,r,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i] >> b[i];
        l=1,r=n;
        while(l <= r)
        {
            m=(l+r) >> 1;
            if(Check(m))l=m+1;
            else r=m-1;
        }
        cout << l-1 << '\n';
    }
    return 0;
}