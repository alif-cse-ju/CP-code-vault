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
int x[N],y[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,_or;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> x[i];
        for(i=2;i<=n;i++)
        {
            y[i]=0;
            if((x[i-1] & x[i]) != x[i-1])
            {
                _or=(x[i-1] | x[i]);
                y[i]=_or ^ x[i];
                x[i]=_or;
            }
        }
        for(i=1;i<=n;i++)cout << y[i] << ' ';
        cout << '\n';
    }
    return 0;
}