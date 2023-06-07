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
ll a[M],ans[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok;
    int i,n,t;
    ll sum,val,x,y;
    cin >> t;
    while(t--)
    {
        sum=0;
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i], sum += a[i];
        if(n == 1)
        {
            cout << "YES\n" << a[1] << '\n';
            continue;
        }
        val=(1ll*n*(n+1))/2;
        if(sum%val)cout << "NO\n";
        else
        {
            ok=1;
            sum /= val;
            for(i=2;i<=n;i++)
            {
                x=sum-(a[i]-a[i-1]);
                if(x <= 0  ||  x%n)
                {
                    ok=0;
                    break;
                }
                ans[i]=x/n;
            }
            val=0;
            for(i=2;i<=n;i++)val += ans[i];
            if(val >= sum)ok=0;
            else ans[1]=sum-val;
            if(!ok)cout << "NO\n";
            else
            {
                cout << "YES\n";
                for(i=1;i<=n;i++)cout << ans[i] << ' ';
                cout << '\n';
            }
        }
    }
    return 0;
}