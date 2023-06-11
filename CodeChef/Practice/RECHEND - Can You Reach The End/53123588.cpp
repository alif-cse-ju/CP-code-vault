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
const int M=3e5+5;
const int N=1e6+5;
const int mod=1e9+7;
pair<int,int>a[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok;
    int i,n,t;
    cin >> t;
    while(t--)
    {
        ok=1;
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i].first >> a[i].second;
        sort(a+1,a+n+1);
        for(i=2;i<=n;i++)
        {
            if(a[i].second == a[i-1].second-1)
            {
                if(a[i].second == 1)
                {
                    ok=0;
                    break;
                }
            }
            else break;
        }
        for(i=n-1;i;i--)
        {
            if(a[i].second == a[i+1].second+1)
            {
                if(a[i].second == n)
                {
                    ok=0;
                    break;
                }
            }
            else break;
        }
        if(!ok)cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}