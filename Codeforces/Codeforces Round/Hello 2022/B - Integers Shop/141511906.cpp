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
const int N=2e6+5;
const int mod=1e9+7;
tuple<ll,ll,ll>a[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,t;
    ll ans,c,l,L,mnl,mxr,n,r,R;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans=mxr=0,mnl=L=R=LLONG_MAX;
        for(i=1;i<=n;i++)
        {
            cin >> l >> r >> c;
            a[i]=make_tuple(l,r,c);
        }
        ans=LLONG_MAX;
        for(i=1;i<=n;i++)
        {
            auto [l,r,c]=a[i];
            if(l < mnl)mnl=l, L=c, ans=LLONG_MAX;
            else if(l == mnl)L=min(L,c);
            if(r > mxr)mxr=r, R=c, ans=LLONG_MAX;
            else if(r == mxr)R=min(R,c);
            if(l == mnl  &&  r == mxr)ans=min(ans,min(L+R, c));
            else ans=min(ans,L+R);
            cout << ans << '\n';
        }
    }
    return 0;
}