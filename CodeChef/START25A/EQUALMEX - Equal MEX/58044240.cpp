#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
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
int cnt[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok;
    int i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=0;i<=n+1;i++)cnt[i]=0;
        for(i=0;i<n+n;i++)cin >> x, ++cnt[x];
        for(i=ok=0;i<=n+1  &&  !ok;i++)
        {
            if(cnt[i] < 2)
            {
                ok=(cnt[i] == 0);
                break;
            }
        }
        if(ok)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}