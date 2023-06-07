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
int a[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,d,i,j,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> d;
        a[n+1]=d;
        for(i=1;i<=n;i++)cin >> a[i];
        ordered_set<int>ost;
        for(i=1;i<=n;i++)ost.insert(a[i]-a[i-1]-1);
        ans=*(ost.find_by_order(0));
        for(i=1;i<=n;i++)
        {
            ost.erase(ost.find_by_order(ost.order_of_key(a[i]-a[i-1]-1)));
            if(i < n)ost.erase(ost.find_by_order(ost.order_of_key(a[i+1]-a[i]-1)));
            ost.insert(a[i+1]-a[i-1]-1);
            x=*(ost.find_by_order((int)ost.size()-1));
            ans=max(ans, min(*(ost.find_by_order(0)), max((x+1)/2-1, d-a[(i == n ? n-1 : n)]-1)));
            ost.insert(a[i]-a[i-1]-1), ost.insert(a[i+1]-a[i]-1);
            if(i < n)ost.erase(ost.find_by_order(ost.order_of_key(a[i+1]-a[i-1]-1)));
        }
        for(i=2;i<=n;i++)ans=min(ans, a[i]-1);
        cout << ans << '\n';
    }
    return 0;
}