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
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[105],b[105];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,m,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> k >> n >> m;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=m;i++)cin >> b[i];
        i=j=1,x=m+n;
        vector<int>ans;
        while(x--)
        {
            if(i <= n  &&  a[i] <= k)
            {
                ans.emplace_back(a[i]);
                if(!a[i])++k;
                ++i;
            }
            else if(j <= m  &&  b[j] <= k)
            {
                ans.emplace_back(b[j]);
                if(!b[j])++k;
                ++j;
            }
            else break;
        }
        if(i > n  &&  j > m)
        {
            for(int it : ans)cout << it << ' ';
        }
        else cout << "-1";
        cout << '\n';
    }
    return 0;
}