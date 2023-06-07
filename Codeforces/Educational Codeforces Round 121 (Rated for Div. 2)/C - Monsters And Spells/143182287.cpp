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
const int mod=1e9+7;
ll h[102],k[102];
ll Check(const ll& n)
    return (n*(n+1))/2;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans,cur;
    int i,j,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> k[i];
        for(i=1;i<=n;i++)cin >> h[i];
        ans=cur=0;
        for(i=n;i;i=j)
        {
            cur=k[i]-h[i];
            for(j=i-1;j;j--)
            {
                if(k[j] > cur)cur=min(cur, k[j]-h[j]);
                else break;
            }
            ans += Check(k[i]-cur);
        }
        cout << ans << '\n';
    }
    return 0;
}