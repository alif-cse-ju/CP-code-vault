#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=5e5+5;
const int N=1e6+5;
const int mod=998244353;
const int blockSize=715;
int a[M],sum[blockSize+2][blockSize];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,j,q,t,x,y;
    cin >> q;
    while(q--)
    {
        cin >> t >> x >> y;
        if(t == 1)
        {
            a[x] += y;
            for(i=1;i<=blockSize;i++)sum[i][x%i] += y;
        }
        else
        {
            if(x <= blockSize)ans=sum[x][y];
            else
            {
                ans=0;
                for(i=y;i<M-4;i+=x)ans += a[i];
            }
            cout << ans << '\n';
        }
    }
    return 0;
}