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
const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;
ll a[M],fr[M],rv[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t;
    ll ans,sum;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        sort(a+1,a+n+1);
        if(n == 2)cout << "0\n";
        else if(n == 3)cout << min(a[2]-a[1], a[3]-a[2]) << '\n';
        else
        {
            set<pair<ll,int>>st;
            for(i=2;i<n;i++)st.insert({a[n]-a[i],i});
            ans=LLONG_MAX;
            fr[0]=rv[n+1]=0;
            for(i=1;i<=n;i++)fr[i] = fr[i-1]+a[i];
            for(i=n;i;i--)rv[i] = rv[i+1]+a[i];
            for(i=1;i<=n;i++)ans=min(ans,i*a[i]-fr[i]+rv[i+1]-(n-i)*a[i]-max(a[n]-a[i],a[i]-a[1]));
            for(i=2;i<n && ans;i++)
            {
                st.erase({a[n]-a[i],i});
                auto it=st.lower_bound({a[i]-a[1],0});
                if(it != st.end())
                {
                    auto [y,id]=*(it);
                    if(id <= i+1)ans=min(ans,abs(y-(a[i]-a[1])));
                }
                if(it != st.begin())
                {
                    auto [x,id]=*(--it);
                    it=st.lower_bound({x,0});
                    auto [xx,idd]=*(it);
                    if(idd <= i+1)ans=min(ans,abs(xx-(a[i]-a[1])));
                }
                st.insert({a[n]-a[i],i});
            }
            cout << ans << '\n';
        }
    }
    return 0;
}